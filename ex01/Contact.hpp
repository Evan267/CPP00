/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:53:11 by eberger           #+#    #+#             */
/*   Updated: 2023/05/09 23:20:55 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{
	public:

	Contact();
	~Contact();
	int	addFirstName(std::string str);
	int	addLastName(std::string str);
	int	addNickName(std::string str);
	int	addPhoneNumber(std::string str);
	int	addDarkestSecret(std::string str);
	void	showFirstName10(void);
	void	showLastName10(void);
	void	showNickName10(void);
	void	showPhoneNumber10(void);
	void	showFirstName(void);
	void	showLastName(void);
	void	showNickName(void);
	void	showPhoneNumber(void);

	private:

	std::string	firstname_;
	std::string	lastname_;
	std::string	nickname_;
	std::string	phoneNumber_;
	std::string	darkestSecret_;
};

#endif
