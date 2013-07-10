#ifndef GUI_HPP
#define	GUI_HPP
namespace tbd {
    //Forward declarations
    class MissionManager;
    class Layer; 
    class Cursor;
    class HPMonitor;
    /**
     * GUI of the shooter phase
     */
    class GUI {
    public:
        /**
         * Constructor of the GUI
         * @param mm The current MissionManager
         */
        GUI(MissionManager* mm);
        ~GUI();
        /** 
         * Updates the gui
         * @param elapsed Milliseconds since last round
         */
        void Update(double elapsed);
        /**
         * Initialize the GUI. Might read the configuration, in the future
         */
        void Init();
    private:
        MissionManager* missionmanager;
        Layer* layer;
        Cursor* cursor;
        HPMonitor* label;
    };
}
#endif	/* GUI_HPP */

