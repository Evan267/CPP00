/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:51:31 by eberger           #+#    #+#             */
/*   Updated: 2023/05/09 23:36:45 by eberger          ###   ########.fr       */
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

int	Contact::addFirstName(std::string str)
{
	if (str.size() == 0)
		return (printError("firstname"));
	this->firstname_ = str;
	return (1);
}

int	Contact::addLastName(std::string str)
{
	if (str.size() == 0)
		return (printError("lastname"));
	this->lastname_ = str;
	return (1);
}

int	Contact::addNickName(std::string str)
{
	if (str.size() == 0)
		return (printError("nickname"));
	this->nickname_ = str;
	return (1);
}

int	Contact::addPhoneNumber(std::string str)
{
	if (str.size() == 0)
		return (printError("phone number"));
	this->phoneNumber_ = str;
	return (1);
}

int	Contact::addDarkestSecret(std::string str)
{
	if (str.size() == 0)
		return (printError("darkest secret"));
	this->darkestSecret_ = str;
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
	printParams10char(this->firstname_);
}

void	Contact::showLastName10(void)
{
	printParams10char(this->lastname_);
}

void	Contact::showNickName10(void)
{
	printParams10char(this->nickname_);
}

void	Contact::showPhoneNumber10(void)
{
	printParams10char(this->phoneNumber_);
}

void	Contact::showFirstName(void)
{
	std::cout << this->firstname_ << std::endl;
}

void	Contact::showLastName(void)
{
	std::cout << this->lastname_ << std::endl;
}

void	Contact::showNickName(void)
{
	std::cout << this->nickname_ << std::endl;
}

void	Contact::showPhoneNumber(void)
{
	std::cout << this->phoneNumber_ << std::endl;
}
