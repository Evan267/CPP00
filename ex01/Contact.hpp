/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:53:11 by eberger           #+#    #+#             */
/*   Updated: 2023/08/09 09:24:29 by eberger          ###   ########.fr       */
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
	int		addFirstName(std::string str, int *error);
	int		addLastName(std::string str, int *error);
	int		addNickName(std::string str, int *error);
	int		addPhoneNumber(std::string str, int *error);
	int		addDarkestSecret(std::string str, int *error);
	void	showFirstName10(void);
	void	showLastName10(void);
	void	showNickName10(void);
	void	showPhoneNumber10(void);
	void	showFirstName(void);
	void	showLastName(void);
	void	showNickName(void);
	void	showPhoneNumber(void);
	void	showDarkestSecret(void);

	private:

	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif
