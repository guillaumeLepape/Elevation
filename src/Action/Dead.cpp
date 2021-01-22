/*!
    * \file Dead.cpp
*/

#include "Dead.h"

#include "Plug.h"

Dead::Dead
(
    const Plug* const plug,
    const std::string& statement,
    const std::string& result
) :
    Action( statement, result ),
    plug_( plug )
{

}

void Dead::triggerAction()
{
    if ( plug_->deadOrNot() )
    {
        actionWriter_.writeResult();
    }
}