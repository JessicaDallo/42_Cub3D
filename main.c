#include "cub3d.h"

bool	check_av(char *map_file, char *prog_name)
{
	if (!ft_strnstr(map_file, ".cub", ft_strlen(map_file)))
	{
		printf("Please try again with the corrects informations! \n");
		printf("%s <maps/map_file.cub>\n", prog_name);
		return (false);
	}
	if (!ft_strnstr(map_file, "/map", ft_strlen(map_file)))
	{
		printf("Please try again with the corrects informations! \n");
		printf("%s <maps/map_file.cub>\n", prog_name);
		return (false);
	}
	return (true);

}

void	init_parse_struct(t_parse *parse)
{
	parse->no = false;
	parse->so = false;
	parse->we = false;
	parse->ea = false;
	parse->floor = false;
	parse->ceiling = false;
}

void	get_number_lines(char *file, int *file_lines)
{
	int		fd;
	char	*line;

	//(*file_lines) = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n the file doesn't exist!\n");
		exit (1);//fazer função para exit e frees;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{ 	
		(*file_lines)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("lines na função %d\n", *file_lines);
}

bool	ft_read_file(t_parse *parse, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if(fd == -1)
	{
		printf("Error\n the file doesn't exist!\n");
		return (false);
	}
	get_number_lines(file, &parse->file_lines);
	printf("lines %d\n", parse->file_lines);
	//continua fazer a leitura do arquivo para o parse->file
	//mas antess disso descobrir quantas linhas tem para fazer o malloc necessario
	//usar get_next_line para pegar cada linha já com o malloc.
	close(fd);
	return (true);
}

int	main(int ac, char **av)
{
	t_cub *cub;
	if(ac != 2)
	{
		printf("Error\nPlease try again with the corrects informations! \n");
		printf("%s <maps/map_file.cub>\n", av[0]);
		return (1);
	}
	if(!check_av(av[1], av[0]))
		return (1);
	cub = malloc (sizeof(t_cub));
	cub->parse = malloc (sizeof(t_parse));
	if(!cub || !cub->parse)
	{
		printf("Error\n Memory allocation error\n");
		return (1);
	}
	init_parse_struct(cub->parse);
	if(!ft_read_file(cub->parse, av[1]))
		return (1);
	//readmap guardar em algum lugar
	//fazer a validadação
	return(0);
}