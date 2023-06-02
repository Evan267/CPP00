/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:47:16 by eberger           #+#    #+#             */
/*   Updated: 2023/05/08 22:46:37 by eberger          ###   ########.fr       */
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
	void	addNewContact(void);
	void	searchContact(void);

	private:

	void		getInput_(void);
	std::string	field_(std::string nameField);
	void		createFields_(int idContact);
	void		showContact_(int id);
	void		showOneLineContact_(int idContact);
	void		showContactList_(void);
	int		getInputId_(void);
	Contact 	contacts_[8];
	int		nbAdd_;
};

#endif
