#ifndef SYMMETRICDATE_H
#define SYMMETRICDATE_H

class SymmetricDate {
public:
    void findDates() const;

private:
    bool isValidDate(int day, int month, int year) const;
};

#endif