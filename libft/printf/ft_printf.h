/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:02:50 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/29 16:38:44 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *c, ...);

int	ft_printchar(char c);

int	ft_printstring(char *c);

int	ft_printnbr(long int c);

int	ft_printhex(unsigned long int c, char *str);

int	ft_printunsigned(unsigned long int c);

int	ft_printpointer(void *addr);

#endif
