/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkebethi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:39:14 by lkebethi          #+#    #+#             */
/*   Updated: 2019/06/22 17:49:16 by lkebethi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			main()
{
// memset
//	char s1[50] = "WeThinkCode_ is the future of Afrika Tech Ind.";

//	ft_memset(s1 + 12, '-', 8);
//	ft_putstr(s1);


// bzero
//	char s1[50] = "WeThinkCode_ is the future of Afrika Tech Ind.";

//	ft_bzero(s1 + 12, 10);
//	ft_putstr(s1);	
//	printf("%s", ft_bzero(s1, 12));

// memcpy
//	char s1[] = "Hello.World";
//	char s2[] = "Hellof";

//	printf("Before copy: %s\n", s1);
//	printf("After copy: %s", ft_memcpy(s2, s1, 6));
	
// memccpy
//	char s1[10] = "Hello";
//	char s2[10] = "World";

//	ft_memccpy(s1, s2, 'l', 6);
//	ft_putstr(s1);
//	printf("%s", ft_memccpy( s2, s1, 'H', 8));

// memmove
//	char s1[10] = "Lebohang";
//	char s2[10] = "Harmony";

//	printf("%s", ft_memmove(s1, s2, 3));

// memchr
//	char s[10] = "Lebohang";

//	printf("Before: %s\n", s);
//	printf("After: %s", ft_memchr(s, 'o', 8));

// memcmp
	
//	printf("After: %d", ft_memcmp(s1, s2, 10));

// memalloc
//	char *str;
//	int *i;

//	i = (int *)ft_memalloc(sizeof(int));
//	*i = 9;
//	str = (char *)ft_memalloc(20);
//	str = "wethinkcode";
//	ft_putstr(str);
//	ft_putnbr(*i);

//	char *str;

//	str = (char *)ft_memalloc(15);
//	str = "Lebo";
//	printf("Address is: %s", str);

// memdel

//	char *str;

//	str = (char *)ft_memalloc(20);
//	str = "wethinkcode";
//	str = (void **)ap
//	ft_memdel(ap);
//	ft_putstr(str);
// putchar

//	char c = 'M';

//	ft_putchar(c);

// putstr
//	ft_putchar('\n');
//	char s[] = "Hello World!";

//	ft_putstr(s);

// putendl

//	char str[] = "Lebo";
//	printf("%s", str);

// putchar_fd

//	char s1 = 'L';

//	ft_putchar_fd(s1, 2);

// putstr_fd
//	char *s;

//	s = "Lebo\n";
//	ft_putstr(s);
//	ft_putstr_fd(s, 1);

// putendl_fd

//	s = "Lebohang";
//	ft_putendl(s);

//	ft_putendl_fd(str, 1);
//	printf("%c", s1);

// putnbr

//	ft_putnbr(10);

// putnbr_fd

//	ft_putnbr_fd(15, 1);

// strlen

//	char s[] = "Lebohang";

//	ft_putnbr(ft_strlen(s));
//	printf("Size of string is: %zu", ft_strlen(s));

// strdup

//	ft_putstr(ft_strdup(s));
// 	printf("%s", ft_strdup(s));

// strcpy

//	char dst[5] = "Lebo";
//	char src[10] = "Harmony";

//	printf("Before copy: %s\n", dst);
//	printf("After copy: %s", ft_strcpy(dst, src));

// strncpy

//	printf("%s\n", ft_strncpy(dst, src, 2));

// strcat & strncat

//	char s1[10] = "Leboha";
//	const char s2[10] = "ng";
	
//	printf("%s", ft_strncat(s1, s2, 2));
	
// strlcat

//	printf("%zu", ft_strlcat(dst, src, 5));

// strchr

//	char s[20] = "Coding is Life";
//	char *s1;

//	s1 = ft_strchr(s, 'i');
//	ft_putstr(s1);
//	printf("%s", ft_strchr(s, 'i'));

// strrchr

//	printf("%s", ft_strrchr(s, 'i'));

// strstr & strnstr

//	const char s1[20] = "Hello, how are you?";
//	const char s2[10] = "yes";
//	char *res;

//	res = ft_strstr(s1, s2);
//	ft_putstr(res);
//	printf("%s", res);

// strcmp & strncmp

//    char s1[10] = "Lebof";
//    char s2[10] = "Lebod";
//	int res;

//	res = ft_strncmp(s1, s2, 6);
//	ft_putnbr(res);
//    printf("%d", ft_strncmp(s1, s2, 2));
    
// strnew

//	char *s = "Lebohang";
//	char *res;

//	ft_putendl(s);
//	res = ft_strnew(2);
//	ft_putstr(res);
//	printf("%s", ft_strnew(2));	

// strdel
//	int i;

//	i = 0;
//	while (s[i])
//	{
//		ft_putchar(ft_strdel(s[i]));
//		i++;
//	}

// strclr

//	printf("%s\n", ft_strclr(s));

// striter 

//	char s[] = "Lebohang";
//	char res;

//	res = ft_striter(s, 'H');
//	ft_putstr(res);
//	printf("%s", ft_striter(s, 'i'));
// strmap
//	char s2[10] = "Harmony";
//	char c = 'i';

//	printf("%s", ft_strmap(s2, c));

// strequ and strnequ
//	char s[] = "Lebof";
//	char s2[] = "Lebof";
//	char str;

//	str = ft_strequ(s, s2);
//	ft_putnbr(str);

//	printf("%d", ft_strequ(s, s2));

// strsub
//	char s[50] = "WeThinkCode is the future of Afrika's Tech Ind.";
//	char *str;

//	str = ft_strsub(s, 0, 25);
//	ft_putendl(str);
//	printf("%s", ft_strsub(s, 4, 4));

// strjoin

	
//	char s1[15] = "Stay Hungry\n";
//	char s2[15] = "Stay Foolish";

//	ft_putendl(ft_strjoin(s1, s2));	
//	printf("%s", ft_strjoin(s1, s2));

// strtrim
//	char s[50] = "\t\t\t\t\t\t Coding is \t\t\t\tF*ckn\t\t\t fun  ";
//	char *str;
		
//	str = ft_strtrim(s);
//	ft_putendl(str);
// strsplit	
	
//	char *s = "yywethinkcodeylebogangyyhello";
//	char c = 'y';
//	char **tab;
//	int	i = 0;

//	tab = ft_strsplit(s, c);
//	while (tab[i])
//	{
//		printf("%s\n", (tab[i]));
// 		i++;
// 	 }

// atoi
	char s[10] = "6";
//	char *str;

//	str = ft_atoi(s);
	ft_putnbr(ft_atoi(s));

	return (0);
}
