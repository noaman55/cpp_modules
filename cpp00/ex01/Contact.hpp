#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        static  int totalNbContacts;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        void display_contact(int	index);
        void set_first_name(std::string name);
        void set_last_name(std::string name);
        void set_nickname(std::string name);
        void set_phone_number(std::string ph_nbr);
        void set_darkest_secret(std::string secret);
        static void set_total_contacts(int value);
        static int get_total_contacts();
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
        ~Contact();
};
#endif


