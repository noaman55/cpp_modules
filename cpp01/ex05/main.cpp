#include "Harl.hpp"

int main( void )
{
    Harl obj;

    obj.complain("INFO");
    obj.complain("DEBUG");
    obj.complain("WARNING");
    obj.complain("ERROR");
    obj.complain("ABCD");
    return (0);
}