/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:12:54 by ebensalt          #+#    #+#             */
/*   Updated: 2022/05/27 10:26:31 by ebensalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putunbr(unsigned int n);
int		ft_puthexa(unsigned int nbr, char *base16);
int		ft_puthexap(unsigned long nbr, char *base16);
int		ft_putstr(char *s);
int		ft_putnbr(int nbr);
void	ft_putchar_fd(char c, int fd);
#endif
