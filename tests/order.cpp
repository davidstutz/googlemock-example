#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "lib/mail_service.hpp"
#include "lib/warehouse.hpp"
#include "lib/order.hpp"

using ::testing::Return;
using ::testing::_; // Matcher for parameters

/** \brief Mock for the warehouse interface.
 * \author David Stutz
 */
class MockWarehouse : public Warehouse
{
public:
    
    // see https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md
    MOCK_CONST_METHOD2(hasInventory, bool(int, std::string));
    MOCK_METHOD2(remove, void(int, std::string));
};

/** \brief Mock for the mail service interface. 
 * \author David Stutz
 */
class MockMailService : public MailService
{
public:
    MockMailService()
    {
        
    }
    
    MOCK_METHOD1(send, void(std::string));
};

TEST(OrderTest, Fill)
{
    MockWarehouse warehouse;
    std::shared_ptr<MockMailService> mailService = std::make_shared<MockMailService>();
    
    Order order(50, "Talisker");
    order.setMailService(mailService);
    
    EXPECT_CALL(warehouse, hasInventory(50, "Talisker"))
        .Times(1)
        .WillOnce(Return(true));
    EXPECT_CALL(warehouse, remove(50, "Talisker"))
        .Times(1);
    
    EXPECT_CALL(*mailService, send(_)) // Not making assumptions on the message send ...
        .Times(1);
    
    ASSERT_TRUE(order.fill(warehouse));
}

/** \brief Main test entrance point. 
 * \param[in] argc
 * \param[in] argv
 */
int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

