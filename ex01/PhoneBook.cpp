/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:28:39 by eberger           #+#    #+#             */
/*   Updated: 2023/08/07 16:05:14 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	this->getInput_();
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::getInput_(void)
{
	std::string	commands;

	nbAdd_ = 0;
	while (commands.empty() || commands.compare("EXIT") != 0)
	{
		std::cout << "commandes : ";
		std::getline(std::cin, commands);
		if (std::cin.good() == 0)
		{
			std::cout << std::endl;
			break;
		}
		else
		{
			if (commands.compare("ADD") == 0)
				this->addNewContact();
			else if (commands.compare("SEARCH") == 0)
				this->searchContact();
			else if (commands.compare("EXIT") != 0)
				std::cerr <<  "commandes inconnu !" << std::endl;
		}
	}
}

std::string	PhoneBook::field_(std::string nameField)
{
	std::string	fieldValue;

	std::cout << nameField << " : ";
	std::cin >> fieldValue;
	return (fieldValue);
}

void	PhoneBook::createFields_(int idContact)
{
	Contact	*contact;

	contact = &contacts_[idContact];
	while (!contact->addFirstName(this->field_("Firstname")));
	while (!contact->addLastName(this->field_("Lastname")));
	while (!contact->addNickName(this->field_("Nickname")));
	while (!contact->addPhoneNumber(this->field_("Phone number")));
	while (!contact->addDarkestSecret(this->field_("Darkest secret")));
}

void	PhoneBook::addNewContact(void)
{
	int	i;

	i = this->nbAdd_ % 8;
	this->createFields_(i);
	this->nbAdd_++;	
}

void	PhoneBook::showOneLineContact_(int idContact)
{
	Contact	*contact;

	contact = &contacts_[idContact];
	std::cout << idContact + 1 << "|";
	contact->showFirstName10();
	std::cout << "|";
	contact->showLastName10();
	std::cout << "|";
	contact->showNickName10();
	std::cout << "|";
	contact->showPhoneNumber10();
	std::cout << std::endl;
}

void	PhoneBook::showContactList_(void)
{
	int	i;

	i = 0;
	while (i < this->nbAdd_ && i < 8)
	{
		this->showOneLineContact_(i);
		i++;
	}
}

int	PhoneBook::getInputId_(void)
{
	int	id;

	id = 0;
	while (!id || id < 1 || id > this->nbAdd_ || id > 8)
	{
		if (id)
			std::cerr << "Id Incorrect" << std::endl;
		std::cout << "Renseigner l'id du contact à afficher : ";
		std::cin >> id;
	}
	return (id - 1);
}

void	PhoneBook::showContact_(int id)
{
	Contact	*contact;

	contact = &contacts_[id];
	contact->showFirstName();
	contact->showLastName();
	contact->showNickName();
	contact->showPhoneNumber();
}

void	PhoneBook::searchContact(void)
{
	int	id;

	if (this->nbAdd_ > 0)
	{
		showContactList_();
		id = getInputId_();
		showContact_(id);
	}
	else
		std::cout << "Aucun contact pour le moment" << std::endl;
}
