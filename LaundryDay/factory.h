
#include <memory>
#include "question.h"
#include "laundryday.h"

class Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() = 0;
};

class LaundryDayFactory : public Factory
{
public:
    virtual std::shared_ptr<Question> CreateInstance() {return std::shared_ptr<Question>(new LaundryDay);}
};

