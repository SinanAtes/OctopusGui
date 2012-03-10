#include <QMainWindow>
#include <QQueue>
#include "settingdialog.h"

class QPushButton;
class QLabel;
class QSpinBox;
class QComboBox;
class QLineEdit;
class QDoubleSpinBox;
class QTextEdit;
class QCheckBox;
class QGroupBox;

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
protected:
    virtual void keyReleaseEvent ( QKeyEvent * event );

private:
    bool controlEmptyFields(void);
    void createActions(void);
    void createMenus(void);
    void setInpText(QString);

private slots:
    void saveAllParameters(void);
    void toggleFullScreenFunction(bool);
    void about();
    void workWithMultiDirectories(int);
    void setInpFilePath();
    void setCsvFilePath();
    void settings();

private:
    QString inpText;
    SettingDialog *settingsDialog; //for settings dialog
    int sensitivity;
    int maxDigit;

    /****Parameters***/
    QString *inpFileName;
    QString *inpFilePath;   //Output directory
    QString *csvFilePath;   //Input directory

    QString *octopusOutPutDir;


    /*****Widgets*****/
    QTabWidget *mainWindowTabs;

    QPushButton *submitButton;
    QPushButton *cancelButton;

    QLabel *dimensionsLabel;
    QSpinBox *dimensionSpin;

    QLabel *flushMessagesLabel;
    QComboBox *flushMessagesCombo;

    QLabel *calculationModeLabel;
    QGroupBox *calculationModeGroupBox;

    QLabel *unitsLabel;
    QComboBox *unitsCombo;

    QLabel *fromScratchLabel;
    QComboBox *fromScratchCombo;

    QLabel *extraStatesLabel;
    QSpinBox *extraStatesSpin;

    QLabel *spinComponentsLabel;
    QComboBox *spinComponentsCombo;

    QLabel *p_cLabel;
    QDoubleSpinBox *p_cDoubleSpin;

    /*%StaticMagneticField0 | 0 | 0.1457106*P_c*0.5% */
    QLabel *staticMagneticFieldLabel;
    QSpinBox *staticMagneticFieldSpin1;
    QSpinBox *staticMagneticFieldSpin2;
    QLabel *staticMagneticP_c;
    QDoubleSpinBox *staticMagneticFieldSpin;

    QLabel *boxShapeLabel;
    QComboBox *boxShapeCombo;

    /*%LSize56 | 56 | 0 %*/
    QLabel *lSizeLabel;
    QSpinBox *lSizeSpin1;
    QSpinBox *lSizeSpin2;
    QSpinBox *lSizeSpin3;

    QLabel *spacingLabel;
    QDoubleSpinBox *spacingDoubleSpin;

    QLabel *NLabel;
    QSpinBox *NSpin;

    QLabel *occupationsLabel;
    QTextEdit *occupationsText;

    //Tab2
    QLabel *derivativesOrderLabel;
    QComboBox *derivativesOrderCombo;

    QLabel *gyroMagneticRatioLabel;
    QSpinBox *gyroMagneticRatioSpin;

    QLabel *LCAOStartLabel;
    QComboBox *LCAOStarCombo;

    QLabel *theoryLevelLabel;
    QComboBox *theoryLevelCombo;

    QLabel *eigenSolverLabel;
    QComboBox *eigenSolverCombo;

    QLabel *maximumIterLabel;
    QSpinBox *maximumIterSpin;

    QLabel *convAbsEvLabel;
    QSpinBox *convAbsEvSpin;

    QLabel *typeOfMixingLabel;
    QComboBox *typeOfMixingCombo;

    QLabel *mixingLabel;
    QDoubleSpinBox *mixingDoubleSpin;

    QLabel *parallelizationStrategyLabel;
    QComboBox *parallelizationStrategyCombo;

    QLabel *speciesLabel;
    QLineEdit *speciesLineEdit1;
    QSpinBox *speciesSpin;
    QComboBox *speciesCombo;
    QLineEdit *speciesLineEdit2;

    QLabel *coordinatesLabel;
    QLineEdit *coordinatesLineEdit;
    QSpinBox *coordinatesSpin1;
    QSpinBox *coordinatesSpin2;
    QComboBox *coordinatesCombo;

    QLabel *outputLabel;
    QGroupBox *outputGroupBox;

    QLabel *outputMatrixElementsLabel;
    QGroupBox *outputMatrixElementsGroupBox;

    QLabel *outputHowLabel;
    QGroupBox *outputHowGroupBox;

    //Multi Directories
    QLabel *multiDirectoriesLabel;
    QCheckBox *multiDirectoriesCheckBox;

    QLabel *initialValueLabel;
    QDoubleSpinBox *initialValueSpin;

    QLabel *lastValueLabel;
    QDoubleSpinBox *lastValueSpin;

    QLabel *increaseLabel;
    QDoubleSpinBox *increaseSpin;

    QLabel *inpFilePathLabel;
    QLineEdit *inpFilePathLine;
    QPushButton *inpFilePathButton;

    QLabel *csvFilePathLabel;
    QLineEdit *csvFilePathLine;
    QPushButton *csvFilePathButton;



             //**QQueu**
    //Calculation Mode
    QQueue <QCheckBox *> calculationModeQQueue;
    QQueue <QCheckBox *> outputQQueue;
    QQueue <QCheckBox *> outputMatrixElementsQQueue;
    QQueue <QCheckBox *> outputHowQQueue;


             //**CheckBoxes**
    //Calculation Mode
    QCheckBox *gs;
    QCheckBox *unacc;
    QCheckBox *td;
    QCheckBox *goopt_control;
    QCheckBox *em_resp;
    QCheckBox *casida;
    QCheckBox *td_transport;
    QCheckBox *vdw;
    QCheckBox *vib_modes;
    QCheckBox *one_shot;
    QCheckBox *kdotp;
    QCheckBox *gcm;
    QCheckBox *dummy;
    QCheckBox *invert_ks;
    QCheckBox *recipe;

    //OutputHow
    QCheckBox *plane_z;
    QCheckBox *matlab;
    QCheckBox *xcrysden;
    QCheckBox *netcdf;
    QCheckBox *cube;
    QCheckBox *binary;
    QCheckBox *plane_y;
    QCheckBox *axis_x;
    QCheckBox *axis_y;
    QCheckBox *etsf;
    QCheckBox *meshgrid;
    QCheckBox *axis_z;
    QCheckBox *meshindex;
    QCheckBox *dx;
    QCheckBox *xyz;
    QCheckBox *boundry_points;
    QCheckBox *plane_x;

    //OutputMatrixElements
    QCheckBox *ang_momentum;
    QCheckBox *ks_multipoles;
    QCheckBox *momentum;
    QCheckBox *one_body;
    QCheckBox *two_body;

    //Output
    QCheckBox *potential;
    QCheckBox *density;
    QCheckBox *matrix_elements;
    QCheckBox *el_pressure;
    QCheckBox *forces;
    QCheckBox *ELF_basins;
    QCheckBox *tpa;
    QCheckBox *kinetic_energy_density;
    QCheckBox *PES_density;
    QCheckBox *geometry;
    QCheckBox *wfs_fourier;
    QCheckBox *ELF_FS;
    QCheckBox *current;
    QCheckBox *PES;
    QCheckBox *pol_density;
    QCheckBox *xc_density;
    QCheckBox *wfs;
    QCheckBox *Bader;
    QCheckBox *modelmb;
    QCheckBox *ELF;
    QCheckBox *dos;
    QCheckBox *BerkeleyGW;
    QCheckBox *mesh_r;
    QCheckBox *PES_wfs;
    QCheckBox *wfs_sqmod;

    /*****Menus*****/
    QMenu *settingsMenu;
    QMenu *viewMenu;
    QMenu *aboutMenu;


    //settings menu actions
    QAction *inpFilePathAction;
    QAction *octopusOutPathPutAction;
    QAction *addNewParameterAction;
    QAction *settingAction;

    //view menu actions
    QAction *toggleFullScreen;

    //about menu actions
    QAction *aboutAction;
};

