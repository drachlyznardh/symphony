#ifndef BACKGROUND_HPP
#define	BACKGROUND_HPP
namespace tbd {
    class Layer; //Forward declaration

    /**
     * Base class to draw stuff in the background.
     * It is non-interactive background, on a different layer.
     * It should be defined by the Mission class.
     */
    class Background {
    public:
        /**
         * Function called every frame
         * @param elapsed milliseconds elapsed since last frame
         */
        virtual void Update(double elapsed) = 0;
    protected:
        /**
         * Constructor of the Background class, does almost nothing
         * @param l Layer that has been assigned to the Background
         */
        Background(Layer* l);
        /**
         * Pointer to assigned layer
         */
        Layer* layer;
    private:
    };
}

#endif	/* BACKGROUND_HPP */

