/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:47:16 by eberger           #+#    #+#             */
/*   Updated: 2023/08/09 09:15:35 by eberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	public:

	PhoneBook(void);
	~PhoneBook(void);
	void	addNewContact(int *error);
	void	searchContact(int *error);

	private:

	void		_getInput(void);
	std::string	_field(std::string nameField, int *error);
	void		_createFields(int idContact, int *error);
	void		_showContact(int id);
	void		_showOneLineContact(int idContact);
	void		_showContactList(void);
	int			_getInputId(int *error);
	Contact 	_contacts[8];
	int			_nbAdd;
};

#endif
