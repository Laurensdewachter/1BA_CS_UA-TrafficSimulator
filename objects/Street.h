#ifndef PSE_STREET_H
#define PSE_STREET_H

#include <iostream>

class Street {
    std::string name;
    int length;

public:
    Street();
    virtual ~Street();

    void setName(const std::string &name);
    void setLength(int length);

    const std::string &getName() const;
    int getLength() const;

};


#endif //PSE_STREET_H
