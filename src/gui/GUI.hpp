/* 
 * File:   GUI.hpp
 * Author: alessio
 *
 */

#ifndef GUI_HPP
#define	GUI_HPP
namespace tbd {
    //Forward declarations
    class MissionManager;
    class Layer; 
    class Cursor;
    /**
     * GUI of the shooter phase
     */
    class GUI {
    public:
        GUI(MissionManager* mm);
        ~GUI();
        void Update(double elapsed);
        void Init();
    private:
        MissionManager* missionmanager;
        Layer* layer;
        Cursor* cursor;
    };
}
#endif	/* GUI_HPP */

