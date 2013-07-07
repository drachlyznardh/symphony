#ifndef DRAWER_HPP
#define	DRAWER_HPP
#include <Polycode.h>

namespace tbd {
    //Forward declaration
    class DrawableEntity;
    /**
 * Interface for a thing that draws. At creation it should be paired with a Drawable Entity
 */
    class Drawer : public Polycode::ScreenEntity {
    public:
        /**
         * Simple constructor (does almost nothing)
         */
        Drawer();
        /**
         * Entity paired with this Drawer
         */
        tbd::DrawableEntity* myEntity;
        /**
         * Updates the position of the Drawer, to follow the paired Entity
         */
        virtual void Update();
    private:

    };

}
#endif	/* DRAWER_HPP */

