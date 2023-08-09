/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:28:39 by eberger           #+#    #+#             */
/*   Updated: 2023/08/09 09:25:06 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	this->_getInput();
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::_getInput(void)
{
	std::string	commands;
	int			error;

	_nbAdd = 0;
	error = 0;
	while (!error
			&& (commands.empty() || commands.compare("EXIT") != 0))
	{
		std::cout << "commandes : ";
		std::cin >> commands;
		if (std::cin.good() == 0)
		{
			std::cout << std::endl;
			break;
		}
		if (commands.compare("ADD") == 0)
			this->addNewContact(&error);
		else if (commands.compare("SEARCH") == 0)
			this->searchContact(&error);
		else if (commands.compare("EXIT") != 0)
			std::cerr <<  "commandes inconnu !" << std::endl;
	}
}

std::string	PhoneBook::_field(std::string nameField, int *error)
{
	std::string	fieldValue;

	std::cout << nameField << " : ";
	std::cin >> fieldValue;
	if (!(std::cin.good()))
	{
		*error = 1;
		std::cout << std::endl;
	}
	return (fieldValue);
}

void	PhoneBook::_createFields(int idContact, int *error)
{
	Contact	*contact;

	contact = &_contacts[idContact];
	while (!(*error) && !contact->addFirstName(this->_field("Firstname", error), error));
	while (!(*error) && !contact->addLastName(this->_field("Lastname", error), error));
	while (!(*error) && !contact->addNickName(this->_field("Nickname", error), error));
	while (!(*error) && !contact->addPhoneNumber(this->_field("Phone number", error), error));
	while (!(*error) && !contact->addDarkestSecret(this->_field("Darkest secret", error), error));
}

void	PhoneBook::addNewContact(int *error)
{
	int	i;

	i = this->_nbAdd % 8;
	this->_createFields(i, error);
	this->_nbAdd++;	
}

void	PhoneBook::_showOneLineContact(int idContact)
{
	Contact	*contact;

	contact = &_contacts[idContact];
	std::cout << "         " << idContact + 1 << "|";
	contact->showFirstName10();
	std::cout << "|";
	contact->showLastName10();
	std::cout << "|";
	contact->showNickName10();
	std::cout << std::endl;
}

void	PhoneBook::_showContactList(void)
{
	int	i;

	i = 0;
	while (i < this->_nbAdd && i < 8)
	{
		this->_showOneLineContact(i);
		i++;
	}
}

int	PhoneBook::_getInputId(int *error)
{
	int			id;
	std::string	input;

	id = 0;
	while (!(*error) && (!id || id < 1 || id > this->_nbAdd || id > 8))
	{
		if (id)
			std::cerr << "Id Incorrect" << std::endl;
		std::cout << "Renseigner l'id du contact à afficher : ";
		std::cin >> input;
		if (!(std::cin.good()))
		{
			std::cout << std::endl;
			*error = 1;
		}
		if (input[0])
			id = (int)(input[0] - '0');
	}
	return (id - 1);
}

void	PhoneBook::_showContact(int id)
{
	Contact	*contact;

	contact = &_contacts[id];
	contact->showFirstName();
	contact->showLastName();
	contact->showNickName();
	contact->showPhoneNumber();
	contact->showDarkestSecret();
}

void	PhoneBook::searchContact(int *error)
{
	int	id;

	if (!(*error))
	{
		if (this->_nbAdd > 0)
		{
			_showContactList();
			id = _getInputId(error);
			if (!(*error))
				_showContact(id);
		}
		else
			std::cout << "Aucun contact pour le moment" << std::endl;
	}
}
