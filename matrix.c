/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 19:10:50 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/04 12:13:59 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

typedef	float	t_matrix[4][4];

void	print_matrix(t_matrix m)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%.0f ", m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("------------------\n");
}

void	init_matrix(t_matrix m)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j++;
		}
		i++;
	}
	m[3][3] = 1;
}

t_vector	mult_vect(t_vector v, t_matrix m)
{
	t_vector	res;

	res.x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0]; // + translation ?
	res.y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1];
	res.z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2];
	return (res);
}

void	mult_matrix(t_matrix m1, t_matrix m2, t_matrix res)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j]
					+ m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
			j++;
		}
		i++;
	}
}

int main()
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	m3;
	t_vector	v;

	v.x = -50;
	v.y = 100;
	v.z = 250;
	init_matrix(m1);
	init_matrix(m2);
	print_matrix(m1);
	mult_matrix(m1, m2, m3);
	print_matrix(m3);
	v = mult_vect(v, m3);
	printf("v = (%.0f %.0f %.0f)\n", v.x, v.y, v.z);
	return (0);
}
