/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   view_func.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amori <amori@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/13 17:32:55 by amori			 #+#	#+#			 */
/*   Updated: 2022/11/13 17:44:37 by amori            ###   ########.fr       */
/*															*/
/* ************************************************************************** */

int	get_view_row_left(int **universe, int width, int row, int all)
{
	int	i;
	int	view;
	int	max;
	int	count;

	view = 0;
	i = 0;
	max = 0;
	count = 0;
	while (i < width)
	{
		count += universe[row][i];
		if (universe[row][i] >= max)
		{
			view ++;
			max = universe[row][i];
		}
		i ++;
	}
	if (count != all)
		return (-1);
	return (view);
}

int	get_view_row_right(int **universe, int width, int row, int all)
{
	int	i;
	int	view;
	int	max;
	int	count;

	view = 0;
	i = 0;
	max = 0;
	count = 0;
	while (i < width)
	{
		count += universe[row][width - 1 - i];
		if (universe[row][width - 1 - i] >= max)
		{
			view ++;
			max = universe[row][width - 1 - i];
		}
		i ++;
	}
	if (count != all)
		return (-1);
	return (view);
}

int	get_view_col_top(int **universe, int width, int col, int all)
{
	int	i;
	int	view;
	int	max;
	int	count;

	view = 0;
	i = 0;
	max = 0;
	count = 0;
	while (i < width)
	{
		count += universe[i][col];
		if (universe[i][col] >= max)
		{
			view ++;
			max = universe[i][col];
		}
		i ++;
	}
	if (all != count)
		return (-1);
	return (view);
}

int	get_view_col_bot(int **universe, int width, int col, int all)
{
	int	i;
	int	view;
	int	max;
	int	count;

	max = 0;
	view = 0;
	i = 0;
	count = 0;
	while (i < width)
	{
		count += universe[width - 1 - i][col];
		if (universe[width - 1 - i][col] >= max)
		{
			max = universe[width - 1 - i][col];
			view ++;
		}
		i ++;
	}
	if (count != all)
		return (-1);
	return (view);
}
