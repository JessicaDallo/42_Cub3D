/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/02/13 16:02:15 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_window(char **argv)
{
	(void)argv;
	t_main	*pgr;

	ft_memset(&pgr, 0, sizeof(pgr));
	pgr->mlx = mlx_init();
	pgr->mlx_win = mlx_new_window(pgr->mlx, 320, 320, "CUB3D");
}

int main(int argc, char **argv)
{
	t_cub *cub;

	if(!check_args(argc ,argv[1], argv[0]))
		return (1);
	cub = malloc (sizeof(t_cub)); //colocar essas duas linhas em um arquivo de init structs
	cub->parse = malloc (sizeof(t_parse));
	if(!cub || !cub->parse)
	{
		printf("Error\n Memory allocation error\n");
		return (1);
	}
	init_parse_struct(cub->parse);
	if(!ft_read_file(cub->parse, argv[1]))
		return (1);
	//readmap guardar em algum lugar
	//fazer a validadação
	return(0);
	init_window(argv);

	return 0;
}
