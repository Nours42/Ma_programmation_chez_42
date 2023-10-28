/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:43:22 by nours42           #+#    #+#             */
/*   Updated: 2023/10/28 18:54:53 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include "Ircserv.hpp"

class	User
{
	private:
	protected:
	public:
		User();
		~User();
		User(User const &ref);
		User &operator=(User const &ref);
};

#endif