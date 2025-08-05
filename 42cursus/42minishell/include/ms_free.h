/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:08:55 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/24 23:29:35 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_FREE_H
# define MS_FREE_H

# include "ms_struct.h"
# include <stdlib.h>
# include <unistd.h>

void	ms_close_fd(t_cmd *cmd);
void	ms_free_split(char **split);
void	ms_free_info(t_ms_info *info);

#endif
