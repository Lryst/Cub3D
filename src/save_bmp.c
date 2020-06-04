#include "../cub3d.h"

void	write_data(int file, t_cub3d *cub)
{
	int x;
	int y;
	int color;

	x = cub->height - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < cub->width)
		{
			color = (unsigned int)(cub->img_iadr + (y * cub->size_line + x * 4));
			write(file, &color, 4);
			y++;
		}
		x--;
	}
}

unsigned char	*ft_info_img_header(t_cub3d *cub)
{
	unsigned char *header;

	header = (unsigned char*)malloc(sizeof(unsigned char) * 40);
	ft_bzero(header, 40);
	header[0] = 40;
	header[4] = (unsigned char)cub->width;
	header[5] = (unsigned char)cub->width >> 8;
	header[6] = (unsigned char)cub->width >> 16;
	header[7] = (unsigned char)cub->width >> 24;
	header[8] = (unsigned char)cub->height;
	header[9] = (unsigned char)cub->height >> 8;
	header[10] = (unsigned char)cub->height >> 16;
	header[11] = (unsigned char)cub->height >> 24;
	header[12] = 1;
	header[14] = 32;
	return(header);
}

unsigned char	*ft_file_header(int size)
{
	unsigned char *header;

	header = (unsigned char*)malloc(sizeof(unsigned char) * 14);
	ft_bzero(header, 14);
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (unsigned char)size;
	header[3] = (unsigned char)size >> 8;
	header[4] = (unsigned char)size >> 16;
	header[5] = (unsigned char)size >> 24;
	header[10] = 54;
	return (header);
}


void	save(t_cub3d *cub)
{
	int file;
	int file_size;
	unsigned char *file_header;
	unsigned char *info_img_header;


	file_size = 54 + 4 * cub->height * cub->width;
	file = open("screenshot_cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0755);
	file_header = ft_file_header(file_size);
	write(file, file_header, 14);
	free(file_header);
	info_img_header = ft_info_img_header(cub);
	write(file, info_img_header, 40);
	free(info_img_header);
	write_data(file, cub);
	//system("cd screenshot && pwd");
	system("open screenshot_cub3d.bmp");
	if (cub->save == 1)
	{
		system("leaks Cub3D");
		exit(EXIT_SUCCESS);
	}
	//exit(EXIT_SUCCESS);
	//boucle pour ecrire limage dans file.
}


/*
ouvrir un fichier avec tout les droits


3 parties :
file header
	14 octets;

info header
ecriture de limage



*/