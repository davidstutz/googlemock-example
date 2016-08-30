#ifndef MAIL_SERVICE_HPP
#define MAIL_SERVICE_HPP

/** \brief Mail service. This represents one of the collaborators of the SUT. 
 * \author David Stutz
 */
class MailService
{
public:
    /** \brief Send a mial.
     * \param[in] message message to send
     */
    virtual void send(std::string message) = 0;
    
};

#endif /* MAIL_SERVICE_HPP */

