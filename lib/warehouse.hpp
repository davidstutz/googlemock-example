#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include <string>

/** \brief Warehouse interface. This interface is one of the collaborators of our SUT.
 * \author David Stutz
 */
class Warehouse
{
public:
    /** \brief Check whether the product in the given quantity is on stock.
     * \param[in] quantity quantity requested
     * \param[in] product product name
     * \return whether the warehouse has the product on stock for the given quantity
     */
    virtual bool hasInventory(int quantity, std::string product) const = 0;
    
    /** \brief Remove the given quantity of the product from the warehouse.
     * \param[in] quantity quantity to remove
     * \param[in] product product name to remove
     */
    virtual void remove(int quantity, std::string product) = 0;
    
};

#endif /* WAREHOUSE_HPP */

