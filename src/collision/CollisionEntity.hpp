#ifndef COLLISIONOBJECT_HPP
#define	COLLISIONOBJECT_HPP
#include <vector>
#include "../DrawableEntity.hpp"

namespace tbd {
    //Forward declaration
    class HitWindow;
    class Drawer;
    /**
     * Entities that can be collided.
     */
    class CollisionEntity : public DrawableEntity{
    public:
        /**
         * Handles the collision with another entity
         * @param window My HitWindow that was hit
         * @param other The entity I collided with
         */
        virtual void handleCollision(HitWindow* window, CollisionEntity* other)=0;
        /**
         * List of HitWindows
         */
        std::vector<HitWindow*> windows;
        /**
         * Constructor of the CollisionEntity
         * @param d Drawer class assigned to this entity
         */
        CollisionEntity(Drawer* d);
        virtual ~CollisionEntity();
    protected:
    };
}
#endif	/* COLLISIONOBJECT_HPP */

