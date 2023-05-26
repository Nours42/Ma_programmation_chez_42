/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:21:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/24 11:30:25 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** Alloue (avec malloc) et retourne un tableau de chaînes de caractères
** obtenu en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur.
** Le tableau doit être terminé par NULL. Renvoie NULL si l'allocation échoue.
** Les quotes entre ' ou " sont considerees comme un seul mot.
*/

/*
	s = la chaine de caratere
	n_break = le nombre de morceaux a decoupe
	index = l'index dans la quote
	in_q = suis-je dans une quote ?
	q = est-ce qu'il y a une quote dans s ?
	q_sort = caractere de depart de la quote (' ou ")
	sp_index = index d'une spart dans s.
	index_in_sp = index dans une spart.
	sp_len = longueur d'une spart.
	liis = dernier index avant de compter la spart;
	result = resultat.
*/
typedef struct s_quote
{
	char const	*s;
	int			n_break;
	int			index;
	int			in_q;
	int			q;
	char		q_sort;
	int			sp_index;
	int			i_in_sp;
	int			sp_len;
	int			liis;
	char		**result;
}				t_quote;

/*
	result n'est pas initialisee ici mais apres le calcul de n_break, 
	car sinon malloc de 0 morceau.
*/
static int	init_quote(t_quote *quote, char const *s)
{
	if (!s || !s[0])
		return (0);
	quote->s = s;
	quote->n_break = 0;
	quote->index = 0;
	quote->q = 0;
	quote->in_q = 0;
	quote->q_sort = 0;
	quote->sp_index = 0;
	quote->i_in_sp = 0;
	quote->sp_len = 0;
	quote->liis = 0;
	return (1);
}

static void	ft_spart_break(t_quote *q)
{
	while (q->s[q->index])
	{
		if (q->s[q->index++] == 32 && q->s[q->index - 1])
		{
			if ((q->s[q->index] == 34 || q->s[q->index] == 39) && q->q == 0
				&& (int)ft_strqlen(q->s, q->index + 1, q->s[q->index]))
			{
				q->q = 1;
				q->q_sort = q->s[q->index];
				q->index += (int)ft_strqlen(q->s, q->index + 1, q->s[q->index]);
				q->index += 2;
			}
			q->n_break++;
			while (q->s[q->index] && q->s[q->index] != 32)
				q->index++;
		}
	}
	if (q->q == 1)
		q->n_break++;
	if (q->s[q->index] == '\0')
		if (q->s[q->index - 1] != 32
			&& (q->s[q->index - 1] != q->q_sort && q->q == 0))
			q->n_break++;
}

//je reutilise sp_index mais ici il ne mesure pas l'index d'une spart.
static void	ft_ico_malloc_error(t_quote *q)
{
	q->sp_index = 0;
	while (q->sp_index < q->index && q->result[q->sp_index])
	{
		free(q->result[q->sp_index]);
		q->sp_index++;
	}
	free(q->result);
}

static void	ft_spart_malloc(t_quote *q)
{
	q->index = 0;
	while (q->s[q->index] && q->sp_index < q->n_break)
	{
		while (q->s[q->index] && q->s[q->index] == 32)
			q->index++;
		q->liis = q->index;
		if (q->q && (q->s[q->index] == q->q_sort) && (q->s[q->index - 1] == 32))
			q->sp_len = (int)ft_strqlen(q->s, q->index, q->q_sort);
		else
			q->sp_len = (int)ft_strqlen(q->s, q->index, 32);
		q->result[q->sp_index] = (char *)malloc(sizeof(char) * (q->sp_len + 1));
		if (q->result[q->sp_index] == NULL)
			return (ft_ico_malloc_error(q));
		while (q->i_in_sp < q->sp_len)
		{
			q->result[q->sp_index][q->i_in_sp] = q->s[q->liis + q->i_in_sp];
			q->i_in_sp++;
		}
		q->result[q->sp_index][q->i_in_sp] = '\0';
		q->sp_len = 0;
		q->sp_index++;
	}
	q->result[q->sp_index] = 0;
}

char	**ft_qsplit(char const *s)
{
	t_quote	quote;

	if (init_quote(&quote, s))
	{
		ft_spart_break(&quote);
		quote.result = (char **)malloc(sizeof(char *) * (quote.n_break + 1));
		if (quote.result == NULL)
			return (NULL);
		quote.result[quote.n_break] = NULL;
		ft_spart_malloc(&quote);
	}
	else
		return (NULL);
	return (quote.result);
}

/*int	main(void)
{
	char	**test;

	test = ft_qsplit("3: test 'quote quote'");
	test = ft_qsplit("3: test \"quote quote\"");
	test = ft_qsplit("4: test qu\"ote quote");
	test = ft_qsplit("4: test 'quote quote");
	test = ft_qsplit("4: test \"quote quote");
	(void)test;
	return (0);
}*/
