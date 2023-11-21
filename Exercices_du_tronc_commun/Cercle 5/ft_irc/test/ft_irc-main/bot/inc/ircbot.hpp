/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircbot.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:19:56 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:19:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IRCBOT_HPP
# define IRCBOT_HPP

# include <string>
# include <iostream>
# include <vector>

std::vector<std::string>	split(std::string str, char delimiter);
std::string					intToString(int num);
int							randInt(int min, int max);
bool						containsOnlyDigits(const std::string &str);

#endif
