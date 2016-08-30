#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <memory>
#include "warehouse.hpp"
#include "mail_service.hpp"

/** \brief An order of a product with quantity. */
class Order
{
public:
    /** \brief Constructor.
     * \param[in] quantity quantity requested
     * \param[in] product product name requested
     */
    Order(int quantity, std::string product)
    {
        this->quantity = quantity;
        this->product = product;
    }
    
    /** \brief Set the mail service to use. 
     * \param[in] mailService the mail service to attach
     */
    void setMailService(std::shared_ptr<MailService> mailService)
    {
        this->mailService = mailService;
    }
    
    /** \brief Fill the order given the warehouse. 
     * \param[in] warehouse the warehouse to use
     * \return whether the operation was successful
     */
    bool fill(Warehouse &warehouse)
    {
        if (warehouse.hasInventory(quantity, product))
        {
            // ...
            warehouse.remove(quantity, product);
            this->mailService->send("Order filled.");
            
            return true;
        }
        else
        {
            // ...
            this->mailService->send("Order not filled.");
            
            return false;
        }
    }
    
private:
    
    /** \brief Product name. */
    std::string product;
    
    /** \brief Quantity requested. */
    int quantity;
    
    /** \brief Mail service to use. */
    std::shared_ptr<MailService> mailService;
};

#endif /* ORDER_HPP */

