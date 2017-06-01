//
// Created by Sorin Sebastian Mircea on 30/05/2017.
//

#ifndef INC_01OBSERVER_IOBSERVER_H
#define INC_01OBSERVER_IOBSERVER_H

/*
 * https://sourcemaking.com/design_patterns/observer/cpp/3
 * https://www.codeproject.com/Articles/328365/Understanding-and-Implementing-Observer-Pattern-in
 */
class IObserver {
public:
    virtual void Update(int value) = 0;
};


#endif //INC_01OBSERVER_IOBSERVER_H
