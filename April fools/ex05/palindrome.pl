# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    palindrome.pl                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 15:47:24 by sdestann          #+#    #+#              #
#    Updated: 2023/04/01 15:53:37 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl

print "Enter a string: ";
chomp (my $str = <>);

if ( $str eq reverse($str) ) {
     print "The string is a palindrome!\n";
}
else {
     print "The string is not a palindrome.\n";
}
