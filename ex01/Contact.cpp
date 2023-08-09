/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:51:31 by eberger           #+#    #+#             */
/*   Updated: 2023/08/09 09:23:51 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int	printError(std::string field)
{
	std::cerr << "Le champ " << field << " ne peut pas etre vide";
	return (0);
}

int	Contact::addFirstName(std::string str, int *error)
{
	if (*error)
		return (0);
	if (str.empty())
		return (printError("firstname"));
	this->_firstname = str;
	return (1);
}

int	Contact::addLastName(std::string str, int *error)
{
	if (*error)
		return (0);
	if (str.empty())
		return (printError("lastname"));
	this->_lastname = str;
	return (1);
}

int	Contact::addNickName(std::string str, int *error)
{
	if (*error)
		return (0);
	if (str.empty())
		return (printError("nickname"));
	this->_nickname = str;
	return (1);
}

int	Contact::addPhoneNumber(std::string str, int *error)
{
	if (*error)
		return (0);
	if (str.empty())
		return (printError("phone number"));
	this->_phoneNumber = str;
	return (1);
}

int	Contact::addDarkestSecret(std::string str, int *error)
{
	if (*error)
		return (0);
	if (str.empty())
		return (printError("darkest secret"));
	this->_darkestSecret = str;
	return (1);
}

void	printParams10char(std::string str) {
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i + j < 10)
	{
		if (i == 9 && str.size() > 10)
		{
			std::cout << ".";
			i++;
		}
		else if (str.size() + i + j < 10)
		{
			std::cout << " ";
			j++;
		}
		else
			std::cout << str[i++];
	}
}

void	Contact::showFirstName10(void)
{
	printParams10char(this->_firstname);
}

void	Contact::showLastName10(void)
{
	printParams10char(this->_lastname);
}

void	Contact::showNickName10(void)
{
	printParams10char(this->_nickname);
}

void	Contact::showPhoneNumber10(void)
{
	printParams10char(this->_phoneNumber);
}

void	Contact::showFirstName(void)
{
	std::cout << this->_firstname << std::endl;
}

void	Contact::showLastName(void)
{
	std::cout << this->_lastname << std::endl;
}

void	Contact::showNickName(void)
{
	std::cout << this->_nickname << std::endl;
}

void	Contact::showPhoneNumber(void)
{
	std::cout << this->_phoneNumber << std::endl;
}

void	Contact ::showDarkestSecret(void)
{
	std::cout << this->_darkestSecret << std::endl;
}
