
#include "../libft/includes/libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char    *get_hardcoded_base(unsigned long long int ibaselen)
{
    char    *str;
    char    c;
    unsigned long long int i;

    i = 0;
    c = '0';

    str = ft_strnew(ibaselen);

    while (i < ibaselen)
    {
        str[i] = c;
        c++;
        i++;
    }
    return (str);
}

char    *get_system_command(char *str, char *enfs, char *mp)
{
    char *buffer;
    char stra[] = "echo ";
    char strb[] = " | encfs -S ";
    char rspace[] = " ";

    buffer = ft_strjoin(stra, str);
    buffer = ft_strjoin(buffer, strb);
    buffer = ft_strjoin(buffer, enfs);
    buffer = ft_strjoin(buffer, rspace);
    buffer = ft_strjoin(buffer, mp);

    ft_putstr(buffer);

    return (buffer);
}

char    *actualy_do_it(long long unsigned int itotal,
					   long long unsigned int ipos,
					   char *rbase,
					   unsigned long long int ibase,
					   unsigned long long int ilen,
					   char *enfs,
					   char *mp)
{
    unsigned long long int i;
    char *str;
    unsigned long long int pos;
    unsigned long long int tmp;
    int ireturn;

    if (enfs || mp) {}
    ireturn = 0;
    if ((str = ft_strnew(ilen + 1)) == NULL)
        return (NULL);
    while (ipos < itotal)
    {
        i = ipos;
        tmp = pos = ilen;
        while (tmp > 0)
            str[--tmp] = rbase[0];
        while (i)
        {
            str[--pos] = rbase[i % ibase];
            i /= ibase;
        }
        if ((ipos % (itotal > 50 ? itotal / 50 : 2)) == 0)
            ft_printf(".");
        ireturn = 1;
		system(get_system_command(str, enfs, mp));
        if (ireturn == 0)
        {
            ft_printf("\n[Found it: %s]\n", str);
            return (NULL);
        }
        ipos++;
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    char *rbase;
    unsigned long long int ilen;
    unsigned long long int ibase;
    unsigned long long int ip;
    unsigned long long int ialen;

    if (argc != 5)
    {
        ft_printf("usage : [(int) Leight] [(*char) base] [(*char) Encrypted folder] [(*char) Where to mount on success]\n");
        return (0);
    }

    ialen = 1;
    rbase = (char *) argv[2];
    ilen = ft_atoi(argv[1]);
    ibase = ft_strlen(rbase);
    ip = ibase;

    printf("===== [basicb] =====\n");
    while (ialen <= ilen)
    {
        printf("Posibilitee(s) pour %llu char(s): %llu\n", ialen, ip);
        actualy_do_it(ip, 0, rbase, ibase, ialen, argv[3], argv[4]);
        ip = pow(ibase, ++ialen);
    }
    return (0);
}
