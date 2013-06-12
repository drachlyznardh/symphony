/* 
 * File:   Cursor.hpp
 * Author: alessio
 *
 */

#ifndef CURSOR_HPP
#define	CURSOR_HPP
#include "../DrawableEntity.hpp"
namespace tbd {

    class Cursor : public DrawableEntity {
    public:
        Cursor();
        void Update(double elapsed);        
    private:
    };

}
#endif	/* CURSOR_HPP */

