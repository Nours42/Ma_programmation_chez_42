/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:01:50 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/16 14:21:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

struct	Data
{
	int	info;
	
	Data();
	Data(int input);
	~Data();
	Data(Data const &ref);
	Data &operator=(Data const &ref);
};

#endif