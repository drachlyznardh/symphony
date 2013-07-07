#ifndef CURSOR_HPP
#define	CURSOR_HPP
#include "../DrawableEntity.hpp"
namespace tbd {
    /**
     * Cursor, follows the mouse and draws a cross
     */
    class Cursor : public DrawableEntity {
    public:
        /**
         * Constructor of the cursor
         */
        Cursor();
        /**
         * Updates the position of the cursor
         * @param elapsed Milliseconds since last round
         */
        void Update(double elapsed);        
    private:
    };

}
#endif	/* CURSOR_HPP */

