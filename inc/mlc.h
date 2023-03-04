/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:59:04 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/04 16:37:30 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLC_H
# define MLC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

/* STRING */
/* standard */
size_t		f_strlen(const char *s);
size_t		f_strnlen(const char *s, size_t n);
size_t		f_strlcpy(char *d, const char *s, size_t n);
size_t		f_strlcat(char *d, const char *s, size_t n);
void		*f_memset(void *s, int c, size_t n);
void		*f_memcpy(void *d, const void *s, size_t n);
void		*f_memmove(void *d, const void *s, size_t n);
void		*f_memchr(const void *s, int c, size_t n);
char		*f_strchr(const char *s, int c);
char		*f_strrchr(const char *s, int c);
char		*f_strdup(const char *str);
char		*f_strnstr(const char *h, const char *n, size_t m);
int			f_strncmp(const char *s1, const char *s2, size_t n);
int			f_memcmp(const void *s1, const void *s2, size_t n);
/* non-standard */
void		*f_memrchr(const void *s, int c, size_t n);

/* STDLIB */
/* standard */
int			f_atoi(const char *s);
void		*f_calloc(size_t n, size_t m);
void		*f_realloc(void *p, size_t n);
/* non-standard */
double		f_atof(const char *s);

/* STDIO */
/* standard */
int			f_printf(const char *s, ...);
/* non-standard */
int			f_putnbr_base(uint64_t n, char *base);

/* CTYPE */
/* standard */
int			f_isalpha(int c);
int			f_isdigit(int c);
int			f_isalnum(int c);
int			f_isascii(int c);
int			f_isprint(int c);
int			f_isupper(int c);
int			f_islower(int c);
int			f_isspace(int c);
int			f_toupper(int c);
int			f_tolower(int c);
/* non-standard */
int			f_isint(const char *s);
int			f_isreal(const char *s);

/* MISC */
uintmax_t	f_abs(intmax_t n);
char		*f_itoa(int n);
char		*f_itoa_base(intmax_t n, char *base);
#endif
