
#ifndef SIMPLETEXT_HPP
#define	SIMPLETEXT_HPP


#include "Drawer.hpp"
#include "PolyScreenLabel.h"
#include <string>
namespace tbd {
/**
 * Simple drawer, will map a text to the entity.
 */
    class SimpleText : public Drawer{
    public:
        /**
         * Creates the text
         * @param text Starting value of the text
         * @param size Height (in pixel) of the text
         */
        SimpleText(const std::string& text, int size);
        /**
         * Changes the text contained in the object
         * @param text The text to be written
         */
        void setText(const std::string& text);
    private:
        Polycode::ScreenLabel* sl;
        
    };
}
#endif	/* SIMPLETEXT_HPP */

