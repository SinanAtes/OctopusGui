#include <QtGui>
#include <QFileDialog>
#include "MainWindow.h"
#include "settingdialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //Temp
    inpFileName = new QString("inp");
    inpFilePath = new QString();
    csvFilePath = new QString();



    /********************************************************************************************/
    /*------------------------------------INITIALIZE WIDGETS------------------------------------*/
    /********************************************************************************************/

    mainWindowTabs = new QTabWidget(this);

    submitButton = new QPushButton(tr("Submit"), this);
    cancelButton = new QPushButton(tr("Cancel"), this);

    dimensionsLabel = new QLabel(tr("Dimensions:"), this);
    dimensionSpin = new QSpinBox(this);

    flushMessagesLabel = new QLabel(tr("FlushMessages:"), this);
    flushMessagesCombo = new QComboBox(this);

    calculationModeLabel = new QLabel(tr("CalculationMode:"), this);
    calculationModeGroupBox = new QGroupBox(this);
    gs = new QCheckBox(tr("gs"),this);
    unacc = new QCheckBox(tr("unacc"),this);
    td = new QCheckBox(tr("td"),this);
    goopt_control = new QCheckBox(tr("goopt_control"),this);
    em_resp = new QCheckBox(tr("em_resp"),this);
    casida = new QCheckBox(tr("casida"),this);
    td_transport = new QCheckBox (tr("td_transport"),this);
    vdw = new QCheckBox(tr("vdw"),this);
    vib_modes = new QCheckBox(tr("vib_modes"),this);
    one_shot = new QCheckBox(tr("one_shot"),this);
    kdotp = new QCheckBox(tr("kdotp"),this);
    gcm = new QCheckBox(tr("gcm"),this);
    dummy = new QCheckBox(tr("dummy"),this);
    invert_ks = new QCheckBox(tr("invert_ks"),this);
    recipe = new QCheckBox(tr("recipe"),this);

    calculationModeQQueue << gs
                          << unacc
                          <<td
                          << goopt_control
                          << em_resp
                          << casida
                          << td_transport
                          << vdw
                          << vib_modes
                          << one_shot
                          << kdotp
                          << gcm
                          << dummy
                          << invert_ks<<recipe;


    unitsLabel = new QLabel(tr("Units:"), this);
    unitsCombo = new QComboBox(this);

    fromScratchLabel = new QLabel(tr("FromScratch:"), this);
    fromScratchCombo = new QComboBox(this);

    extraStatesLabel = new QLabel(tr("ExtraStates:"), this);
    extraStatesSpin = new QSpinBox(this);

    spinComponentsLabel = new QLabel(tr("SpinComponents:"), this);
    spinComponentsCombo = new QComboBox(this);

    p_cLabel = new QLabel(tr("P_c:"), this);
    p_cDoubleSpin = new QDoubleSpinBox(this);

    /*%StaticMagneticField0 | 0 | 0.1457106*P_c*0.5% */

    boxShapeLabel = new QLabel(tr("BoxShape:"), this);
    boxShapeCombo = new QComboBox(this);

    /*%LSize56 | 56 | 0 %*/
    lSizeLabel = new QLabel(tr("LSize:"),this);
    lSizeSpin1 = new QSpinBox(this);
    lSizeSpin2 = new QSpinBox(this);
    lSizeSpin3 = new QSpinBox(this);

    spacingLabel = new QLabel(tr("Spacing:"), this);
    spacingDoubleSpin = new QDoubleSpinBox(this);

    NLabel = new QLabel(tr("N:"),this);
    NSpin = new QSpinBox(this);

    occupationsLabel = new QLabel(tr("Occupations:"),this);
    occupationsText = new QTextEdit(this);

    //Tab2
    derivativesOrderLabel = new QLabel(tr("Derivatives Order:"),this);
    derivativesOrderCombo = new QComboBox(this);

    gyroMagneticRatioLabel = new QLabel(tr("GyroMagneticRatio: "), this);
    gyroMagneticRatioSpin = new QSpinBox(this);

    LCAOStartLabel = new QLabel(tr("LCAOStart:"), this);
    LCAOStarCombo = new QComboBox(this);

    theoryLevelLabel = new QLabel(tr("TheoryLevel:"), this);
    theoryLevelCombo = new QComboBox(this);

    eigenSolverLabel = new QLabel(tr("EigenSolver:"), this);
    eigenSolverCombo = new QComboBox(this);

    maximumIterLabel = new QLabel(tr("MaximumIter:"), this);
    maximumIterSpin = new QSpinBox(this);

    convAbsEvLabel = new QLabel(tr("ConvAbsEv (1e-x):"),this);
    convAbsEvSpin = new QSpinBox(this);

    typeOfMixingLabel = new QLabel(tr("TypeOfMixing:"), this);
    typeOfMixingCombo = new QComboBox(this);

    mixingLabel = new QLabel(tr("Mixing:"), this);
    mixingDoubleSpin = new QDoubleSpinBox(this);

    parallelizationStrategyLabel = new QLabel(tr("ParallelizationStrategy:"), this);
    parallelizationStrategyCombo = new QComboBox(this);

    speciesLabel = new QLabel(tr("Species:"),this);
    speciesLineEdit1 = new QLineEdit(this);
    speciesSpin = new QSpinBox(this);
    speciesCombo = new QComboBox(this);
    speciesLineEdit2 = new QLineEdit(this);

    coordinatesLabel = new QLabel(tr("Coordinates:"),this);
    coordinatesLineEdit = new QLineEdit(this);
    coordinatesSpin1 = new QSpinBox(this);
    coordinatesSpin2 = new QSpinBox(this);
    coordinatesCombo = new QComboBox(this);

    staticMagneticFieldLabel = new QLabel(tr("Static Magnetic Field:"),this);
    staticMagneticFieldSpin1 = new QSpinBox(this);
    staticMagneticFieldSpin2 = new QSpinBox(this);
    staticMagneticFieldSpin = new QDoubleSpinBox(this);
    staticMagneticP_c = new QLabel(this);

    //Tab3
    outputLabel = new QLabel(tr("Output:"), this);
    outputGroupBox = new QGroupBox(this);

    Bader = new QCheckBox(tr("Bader"),this);
    BerkeleyGW = new QCheckBox(tr("BerkeleyGW"),this);
    current = new QCheckBox(tr("current"),this);
    density = new QCheckBox(tr("density"),this);
    dos = new QCheckBox(tr("dos"),this);
    el_pressure = new QCheckBox(tr("el_pressure"),this);
    ELF = new QCheckBox(tr("ELF"),this);
    ELF_basins = new QCheckBox(tr("ELF_basins"),this);
    ELF_FS = new QCheckBox(tr("ELF_FS"),this);
    forces = new QCheckBox(tr("forces"),this);
    geometry = new QCheckBox(tr("geometry"),this);
    kinetic_energy_density = new QCheckBox(tr("kinetic_energy_density"),this);
    matrix_elements = new QCheckBox(tr("matrix_elements"),this);
    mesh_r = new QCheckBox(tr("mesh_r"),this);
    modelmb = new QCheckBox(tr("modelmb"),this);
    PES = new QCheckBox(tr("PES"),this);
    PES_density = new QCheckBox(tr("PES_density"),this);
    PES_wfs = new QCheckBox(tr("PES_wfs"),this);
    potential = new QCheckBox(tr("potential"),this);
    pol_density = new QCheckBox(tr("pol_density"),this);
    tpa = new QCheckBox(tr("tpa"),this);
    wfs = new QCheckBox(tr("wfs"),this);
    wfs_fourier = new QCheckBox(tr("wfs_fourior"),this);
    wfs_sqmod = new QCheckBox(tr("wfs_sqmod"),this);
    xc_density = new QCheckBox(tr("xc_density"),this);

    outputQQueue << Bader
                 << BerkeleyGW
                 << current
                 << density
                 << dos
                 << el_pressure
                 << ELF
                 << ELF_basins
                 << ELF_FS
                 << forces
                 << geometry
                 << kinetic_energy_density
                 << matrix_elements
                 << mesh_r
                 << modelmb
                 << PES
                 << PES_density
                 << PES_wfs
                 << potential
                 << pol_density
                 << tpa
                 << wfs
                 << wfs_fourier
                 << wfs_sqmod
                 <<xc_density;


    outputMatrixElementsLabel = new QLabel(tr("OutputMatrixElements:"), this);
    outputMatrixElementsGroupBox = new QGroupBox(this);

    ang_momentum = new QCheckBox(tr("ang_momentum"),this);
    ks_multipoles = new QCheckBox(tr("ks_multipoles"),this);
    momentum = new QCheckBox(tr("momentum"),this);
    one_body = new QCheckBox(tr("one_body"),this);
    two_body = new QCheckBox(tr("two_body"),this);

    outputMatrixElementsQQueue<<ang_momentum<<ks_multipoles<<momentum
                                <<one_body<<two_body;

    outputHowLabel = new QLabel(tr("OutputHow:"), this);
    outputHowGroupBox = new QGroupBox(this);

    axis_x = new QCheckBox(tr("axis_x"),this);
    axis_y = new QCheckBox(tr("axis_y"),this);
    axis_z = new QCheckBox(tr("axis_z"),this);
    plane_x = new QCheckBox(tr("plane_x"),this);
    plane_y = new QCheckBox(tr("plane_y"),this);
    plane_z = new QCheckBox(tr("plane_z"),this);
    boundry_points = new QCheckBox(tr("boundry_points"),this);
    binary = new QCheckBox(tr("binary"),this);
    cube = new QCheckBox(tr("cube"),this);
    dx = new QCheckBox(tr("dx"),this);
    etsf = new QCheckBox(tr("etsf"),this);
    matlab = new QCheckBox(tr("matlab"),this);
    meshgrid = new QCheckBox(tr("meshgrid"),this);
    meshindex = new QCheckBox(tr("meshindex"),this);
    netcdf = new QCheckBox(tr("netcdf"));
    xcrysden = new QCheckBox(tr("xcrysden"),this);
    xyz = new QCheckBox(tr("xyz"),this);

    outputHowQQueue << axis_x
                    << axis_y
                    << axis_z
                    << plane_x
                    << plane_y
                    << plane_z
                    << boundry_points
                    << binary
                    << cube
                    << dx
                    << etsf
                    << matlab
                    << meshgrid
                    << meshindex
                    << netcdf
                    << xcrysden
                    << xyz;

    //Multi Directories
    multiDirectoriesLabel = new QLabel(tr("Work with multi-directories:"),this);
    multiDirectoriesCheckBox = new QCheckBox(tr("Multi-Directories"),this);

    initialValueLabel = new QLabel(tr("First value of  Magnetic Field :"),this);
    initialValueSpin = new QDoubleSpinBox(this);

    lastValueLabel = new QLabel(tr("Last value of Magnetic Field :"),this);
    lastValueSpin = new QDoubleSpinBox(this);

    increaseLabel = new QLabel(tr("Amount of increase :"),this);
    increaseSpin = new QDoubleSpinBox(this);

    inpFilePathLabel = new QLabel(tr("Inp File Out Directory :"),this);
    inpFilePathLine = new QLineEdit(this);
    inpFilePathButton = new QPushButton(tr("Open"),this);

    csvFilePathLabel = new QLabel(tr(".csv File input Directory :"),this);
    csvFilePathLine = new QLineEdit(this);
    csvFilePathButton = new QPushButton(tr("Open"),this);

    /********************************************************************************************/
    /*-------------------------------SETTING WIDGET'S PROPERTIES--------------------------------*/
    /********************************************************************************************/

    mainWindowTabs->setTabPosition(QTabWidget::West);

    //set combos "editable = true" to user can enter value, via keyboard
    flushMessagesCombo->setEditable(true);
    unitsCombo->setEditable(true);
    fromScratchCombo->setEditable(true);
    spinComponentsCombo->setEditable(true);
    boxShapeCombo->setEditable(true);
    LCAOStarCombo->setEditable(true);
    theoryLevelCombo->setEditable(true);
    eigenSolverCombo->setEditable(true);
    typeOfMixingCombo->setEditable(true);
    coordinatesCombo->setEditable(true);

    inpFilePathLine->setEnabled(false);
    csvFilePathLine->setEnabled(false);

    dimensionSpin->setRange(0,3);

    flushMessagesCombo->addItem(tr("yes"));
    flushMessagesCombo->addItem(tr("no"));

    QStringList unitsList;
    unitsList << "atomic"
              << "ev_angstrom"
              << "femtoseconds" ;
    unitsCombo->addItems(unitsList);

    fromScratchCombo->addItem(tr("false"));
    fromScratchCombo->addItem(tr("true"));

    QStringList spinComponentsList;
    spinComponentsList << "unpolarized"
                       << "spin_polarized"
                       << "spinors";
    spinComponentsCombo->addItems(spinComponentsList);

    QStringList boxShapeList;
    boxShapeList << "minimum"
                 << "sphere"
                 << "cylinder"
                 << "parallelepiped"
                 << "box_image"
                 << "hypercube"
                 << "user_defined";
    boxShapeCombo->addItems(boxShapeList);

    //Tab2
    derivativesOrderCombo->addItem("2");
    derivativesOrderCombo->addItem("3");
    derivativesOrderCombo->addItem("4");

    QStringList LCAOStartList;
    LCAOStartList<< "lcao_none"
                 << "lcao_states"
                 << "lcao_full";
    LCAOStarCombo->addItems(LCAOStartList);

    QStringList theoryLevelList;
    theoryLevelList<< "dft"
                   << "hartree"
                   << "independent_particles"
                   << "hartree_fock"
                   << "classical";
    theoryLevelCombo->addItems(theoryLevelList);

    QStringList eigenSolverList;
    eigenSolverList<< "rmmdiis"
                   << "plan"
                   << "cg"
                   << "cg_new"
                   << "multigrid"
                   << "lobpcg"
                   << "evolution";
    eigenSolverCombo->addItems(eigenSolverList);

    QStringList typeOfMixingList;
    typeOfMixingList<< "broyden"
                    << "gl_pulay"
                    << "linear";
    typeOfMixingCombo->addItems(typeOfMixingList);

    QStringList parallelizationStrategyList;
    parallelizationStrategyList<< "par_domains"
                               << "par_kpoints"
                               << "par_other"
                               << "par_states"
                               << "serial";
    parallelizationStrategyCombo->addItems(parallelizationStrategyList);

    QStringList speciesList;
    speciesList << "spec_ps_psf"
                << "spec_ps_hgh"
                << "spec_ps_cpi"
                << "spec_ps_fhi"
                << "spec_ps_upf"
                << "spec_user_defined"
                << "spec_full_gaussian"
                << "speche_charge_density"
                << "species_from_file"
                << "spec_full_delta"
                << "spec_point"
                << "spec_jelli"
                << "spec_jelli_slab";
    speciesCombo->addItems(speciesList);

    coordinatesCombo->addItem(tr("yes"));
    coordinatesCombo->addItem(tr("no"));

    initialValueSpin->setEnabled(false);
    lastValueSpin->setEnabled(false);
    increaseSpin->setEnabled(false);

    p_cDoubleSpin->setMaximum(maxDigit);
    p_cDoubleSpin->setDecimals(sensitivity);
    p_cDoubleSpin->setValue(137.036);

    staticMagneticP_c->setText("137.036");

    initialValueSpin->setMaximum(maxDigit);
    initialValueSpin->setDecimals(sensitivity);

    lastValueSpin->setMaximum(maxDigit);
    lastValueSpin->setDecimals(sensitivity);

    increaseSpin->setDecimals(sensitivity);

    *inpFilePath = QDir::currentPath();
    inpFilePathLine->setText(*inpFilePath);

    *csvFilePath = QDir::currentPath();
    csvFilePathLine->setText(*csvFilePath);

    /********************************************************************************************/
    /*-------------------------------------SIGNAL AND SLOTS-------------------------------------*/
    /********************************************************************************************/

    connect(submitButton, SIGNAL(clicked()), this, SLOT(saveAllParameters()));
    connect(multiDirectoriesCheckBox,SIGNAL(stateChanged(int)),this,SLOT(workWithMultiDirectories(int)));
    connect(p_cDoubleSpin,SIGNAL(valueChanged(QString)),staticMagneticP_c,SLOT(setText(QString)));
    connect(cancelButton, SIGNAL(clicked()),this,SLOT(close()));
    connect(inpFilePathButton,SIGNAL(clicked()),this,SLOT(setInpFilePath()));
    connect(csvFilePathButton,SIGNAL(clicked()),this,SLOT(setCsvFilePath()));

    /********************************************************************************************/
    /*------------------------------------SETTING LAYOUTS---------------------------------------*/
    /********************************************************************************************/

    QVBoxLayout *mainVBoxLayout = new QVBoxLayout;
    QGridLayout *mainGridLayout = new QGridLayout;
    QHBoxLayout *mainHBoxLayout = new QHBoxLayout;

    mainGridLayout->addWidget(this->dimensionsLabel, 0, 0);
    mainGridLayout->addWidget(this->dimensionSpin, 0, 1);

    mainGridLayout->addWidget(this->flushMessagesLabel, 1, 0);
    mainGridLayout->addWidget(this->flushMessagesCombo, 1, 1);

    mainGridLayout->addWidget(this->calculationModeLabel, 2, 0);
    QGridLayout *calculationModeCheckBoxLayout = new QGridLayout;
    calculationModeCheckBoxLayout->addWidget(gs,0,0);
    calculationModeCheckBoxLayout->addWidget(unacc,0,1);
    calculationModeCheckBoxLayout->addWidget(td,0,2);
    calculationModeCheckBoxLayout->addWidget(goopt_control,1,0);
    calculationModeCheckBoxLayout->addWidget(em_resp,1,1);
    calculationModeCheckBoxLayout->addWidget(casida,1,2);
    calculationModeCheckBoxLayout->addWidget(td_transport,2,0);
    calculationModeCheckBoxLayout->addWidget(vdw,2,1);
    calculationModeCheckBoxLayout->addWidget(vib_modes,2,2);
    calculationModeCheckBoxLayout->addWidget(one_shot,3,0);
    calculationModeCheckBoxLayout->addWidget(kdotp,3,1);
    calculationModeCheckBoxLayout->addWidget(gcm,3,2);
    calculationModeCheckBoxLayout->addWidget(dummy,4,0);
    calculationModeCheckBoxLayout->addWidget(invert_ks,4,1);
    calculationModeCheckBoxLayout->addWidget(recipe,4,2);
    calculationModeGroupBox->setLayout(calculationModeCheckBoxLayout);
    mainGridLayout->addWidget(calculationModeGroupBox,2,1);

    mainGridLayout->addWidget(this->unitsLabel, 3, 0);
    mainGridLayout->addWidget(this->unitsCombo, 3, 1);

    mainGridLayout->addWidget(this->fromScratchLabel, 4, 0);
    mainGridLayout->addWidget(this->fromScratchCombo, 4, 1);

    mainGridLayout->addWidget(this->extraStatesLabel, 5, 0);
    mainGridLayout->addWidget(this->extraStatesSpin, 5, 1);

    mainGridLayout->addWidget(this->spinComponentsLabel, 6, 0);
    mainGridLayout->addWidget(this->spinComponentsCombo, 6, 1);

    mainGridLayout->addWidget(this->p_cLabel, 7, 0);
    mainGridLayout->addWidget(this->p_cDoubleSpin, 7, 1);

    mainGridLayout->addWidget(this->boxShapeLabel, 8, 0);
    mainGridLayout->addWidget(this->boxShapeCombo, 8 ,1);

    QHBoxLayout *lSizeSpinLayout = new QHBoxLayout;
    lSizeSpinLayout->addWidget(lSizeSpin1);
    lSizeSpinLayout->addWidget(lSizeSpin2);
    lSizeSpinLayout->addWidget(lSizeSpin3);
    mainGridLayout->addWidget(this->lSizeLabel,9,0);
    mainGridLayout->addLayout(lSizeSpinLayout,9,1);

    mainGridLayout->addWidget(this->spacingLabel, 10, 0);
    mainGridLayout->addWidget(this->spacingDoubleSpin, 10, 1);

    mainGridLayout->addWidget(this->NLabel, 12, 0);
    mainGridLayout->addWidget(this->NSpin, 12, 1);

    QVBoxLayout *occupationsLayout = new QVBoxLayout;
    occupationsLayout->addWidget(this->occupationsLabel);
    occupationsLayout->addStretch();
    mainGridLayout->addLayout(occupationsLayout, 13, 0);
    mainGridLayout->addWidget(this->occupationsText, 13, 1);


    mainVBoxLayout->addLayout(mainGridLayout);
    mainVBoxLayout->addStretch(0);

    QWidget *tmpWidget = new QWidget(this);
    tmpWidget->setLayout(mainVBoxLayout);
    mainWindowTabs->addTab(tmpWidget, "Tab 1");


    mainVBoxLayout = new QVBoxLayout;
    mainGridLayout = new QGridLayout;

    mainGridLayout->addWidget(derivativesOrderLabel,10,0);
    mainGridLayout->addWidget(derivativesOrderCombo,10,1);

    mainGridLayout->addWidget(this->gyroMagneticRatioLabel, 11, 0);
    mainGridLayout->addWidget(this->gyroMagneticRatioSpin, 11, 1);

    mainGridLayout->addWidget(this->LCAOStartLabel, 12, 0);
    mainGridLayout->addWidget(this->LCAOStarCombo, 12, 1);

    mainGridLayout->addWidget(this->theoryLevelLabel, 13, 0);
    mainGridLayout->addWidget(this->theoryLevelCombo, 13, 1);

    mainGridLayout->addWidget(this->eigenSolverLabel, 14, 0);
    mainGridLayout->addWidget(this->eigenSolverCombo, 14, 1);

    mainGridLayout->addWidget(this->maximumIterLabel, 15, 0);
    mainGridLayout->addWidget(this->maximumIterSpin, 15, 1);

    mainGridLayout->addWidget(this->convAbsEvLabel,16,0);
    mainGridLayout->addWidget(this->convAbsEvSpin,16,1);

    mainGridLayout->addWidget(this->typeOfMixingLabel, 17, 0);
    mainGridLayout->addWidget(this->typeOfMixingCombo, 17, 1);

    mainGridLayout->addWidget(this->mixingLabel, 18, 0);
    mainGridLayout->addWidget(this->mixingDoubleSpin, 18, 1);

    mainGridLayout->addWidget(this->parallelizationStrategyLabel, 19, 0);
    mainGridLayout->addWidget(this->parallelizationStrategyCombo, 19, 1);

    mainGridLayout->addWidget(this->speciesLabel,20,0);
    QHBoxLayout *speciesLayout = new QHBoxLayout;
    speciesLayout->addWidget(this->speciesLineEdit1);
    speciesLayout->addWidget(this->speciesSpin);
    speciesLayout->addWidget(this->speciesCombo);
    speciesLayout->addWidget(this->speciesLineEdit2);
    mainGridLayout->addLayout(speciesLayout,20,1);

    mainGridLayout->addWidget(this->coordinatesLabel,21,0);
    QHBoxLayout *coordinatesLayout = new QHBoxLayout;
    coordinatesLayout->addWidget(this->coordinatesLineEdit);
    coordinatesLayout->addWidget(this->coordinatesSpin1);
    coordinatesLayout->addWidget(this->coordinatesSpin2);
    coordinatesLayout->addWidget(this->coordinatesCombo);
    mainGridLayout->addLayout(coordinatesLayout,21,1);

    mainGridLayout->addWidget(this->staticMagneticFieldLabel,22,0);
    QHBoxLayout *staticMagneticFieldLayout = new QHBoxLayout;
    staticMagneticFieldLayout->addWidget(this->staticMagneticFieldSpin1);
    staticMagneticFieldLayout->addWidget(this->staticMagneticFieldSpin2);
    staticMagneticFieldLayout->addWidget(this->staticMagneticP_c);
    staticMagneticFieldLayout->addWidget(this->staticMagneticFieldSpin);
    mainGridLayout->addLayout(staticMagneticFieldLayout,22,1);

    mainGridLayout->addWidget(this->inpFilePathLabel,23,0);
    QHBoxLayout *inpFileLayout = new QHBoxLayout;
    inpFileLayout->addWidget(this->inpFilePathLine);
    inpFileLayout->addWidget(this->inpFilePathButton);
    mainGridLayout->addLayout(inpFileLayout,23,1);

    mainGridLayout->addWidget(this->csvFilePathLabel,24,0);
    QHBoxLayout *csvFileLayout = new QHBoxLayout;
    csvFileLayout->addWidget(this->csvFilePathLine);
    csvFileLayout->addWidget(this->csvFilePathButton);
    mainGridLayout->addLayout(csvFileLayout,24,1);

    mainGridLayout->addWidget(this->multiDirectoriesLabel,25,0);
    mainGridLayout->addWidget(this->multiDirectoriesCheckBox,25,1);

    mainGridLayout->addWidget(this->initialValueLabel,26,0);
    mainGridLayout->addWidget(this->initialValueSpin,26,1);

    mainGridLayout->addWidget(this->lastValueLabel,27,0);
    mainGridLayout->addWidget(this->lastValueSpin,27,1);

    mainGridLayout->addWidget(this->increaseLabel,28,0);
    mainGridLayout->addWidget(this->increaseSpin,28,1);




    mainVBoxLayout->addLayout(mainGridLayout);
    mainVBoxLayout->addStretch(0);

    tmpWidget = new QWidget(this);
    tmpWidget->setLayout(mainVBoxLayout);
    mainWindowTabs->addTab(tmpWidget, "Tab 2");

    mainVBoxLayout = new QVBoxLayout;
    mainGridLayout = new QGridLayout;

    mainGridLayout->addWidget(this->outputLabel, 20, 0);
    QGridLayout *outputLayout = new QGridLayout;
    outputLayout->addWidget(Bader,0,0);
    outputLayout->addWidget(BerkeleyGW,0,1);
    outputLayout->addWidget(current,0,2);
    outputLayout->addWidget(density,0,3);
    outputLayout->addWidget(dos,0,4);
    outputLayout->addWidget(el_pressure,1,0);
    outputLayout->addWidget(ELF,1,1);
    outputLayout->addWidget(ELF_basins,1,2);
    outputLayout->addWidget(ELF_FS,1,3);
    outputLayout->addWidget(forces,1,4);
    outputLayout->addWidget(geometry,2,0);
    outputLayout->addWidget(kinetic_energy_density,2,1);
    outputLayout->addWidget(matrix_elements,2,2);
    outputLayout->addWidget(mesh_r,2,3);
    outputLayout->addWidget(modelmb,2,4);
    outputLayout->addWidget(PES,3,0);
    outputLayout->addWidget(PES_density,3,1);
    outputLayout->addWidget(PES_wfs,3,2);
    outputLayout->addWidget(potential,3,3);
    outputLayout->addWidget(pol_density,3,4);
    outputLayout->addWidget(tpa,4,0);
    outputLayout->addWidget(wfs,4,1);
    outputLayout->addWidget(wfs_fourier,4,2);
    outputLayout->addWidget(wfs_sqmod,4,3);
    outputLayout->addWidget(xc_density,4,4);
    outputGroupBox->setLayout(outputLayout);
    mainGridLayout->addWidget(this->outputGroupBox, 20, 1);

    mainGridLayout->addWidget(this->outputMatrixElementsLabel, 21, 0);
    QGridLayout *outputMatrixElementsLayout = new QGridLayout;
    outputMatrixElementsLayout->addWidget(ang_momentum,0,0);
    outputMatrixElementsLayout->addWidget(ks_multipoles,0,1);
    outputMatrixElementsLayout->addWidget(momentum,0,2);
    outputMatrixElementsLayout->addWidget(one_body,1,0);
    outputMatrixElementsLayout->addWidget(two_body,1,1);
    outputMatrixElementsGroupBox->setLayout(outputMatrixElementsLayout);
    mainGridLayout->addWidget(this->outputMatrixElementsGroupBox, 21, 1);

    mainGridLayout->addWidget(this->outputHowLabel, 22, 0);
    QGridLayout *outputHowLayout = new QGridLayout;
    outputHowLayout->addWidget(axis_x,0,0);
    outputHowLayout->addWidget(axis_y,0,1);
    outputHowLayout->addWidget(axis_z,0,2);
    outputHowLayout->addWidget(plane_x,1,0);
    outputHowLayout->addWidget(plane_y,1,1);
    outputHowLayout->addWidget(plane_z,1,2);
    outputHowLayout->addWidget(boundry_points,2,0);
    outputHowLayout->addWidget(binary,2,1);
    outputHowLayout->addWidget(cube,2,2);
    outputHowLayout->addWidget(dx,3,0);
    outputHowLayout->addWidget(etsf,3,1);
    outputHowLayout->addWidget(matlab,3,2);
    outputHowLayout->addWidget(meshgrid,4,0);
    outputHowLayout->addWidget(meshindex,4,1);
    outputHowLayout->addWidget(netcdf,4,2);
    outputHowLayout->addWidget(xcrysden,5,0);
    outputHowLayout->addWidget(xyz,5,2);
    outputHowGroupBox->setLayout(outputHowLayout);
    mainGridLayout->addWidget(this->outputHowGroupBox, 22, 1);


    mainVBoxLayout->addLayout(mainGridLayout);
    mainVBoxLayout->addStretch(0);

    tmpWidget = new QWidget(this);
    tmpWidget->setLayout(mainVBoxLayout);
    mainWindowTabs->addTab(tmpWidget, "Output");

    mainVBoxLayout->addLayout(mainGridLayout);
    mainVBoxLayout->addStretch(0);



    mainVBoxLayout = new QVBoxLayout;
    mainVBoxLayout->addWidget(mainWindowTabs);

    QHBoxLayout *tmpHBox = new QHBoxLayout;
    tmpHBox->addStretch();
    tmpHBox->addWidget(this->cancelButton);
    tmpHBox->addWidget(this->submitButton);

    mainVBoxLayout->addLayout(tmpHBox);

    QScrollArea *mainScrollArea = new QScrollArea(this); // mainwindow can be bigger than screen size
    tmpWidget = new QWidget(this);
    tmpWidget->setLayout(mainVBoxLayout);
    mainScrollArea->setWidget(tmpWidget);

    this->createActions();
    this->createMenus();
    this->setCentralWidget(mainScrollArea);
    this->showMaximized();



}

///////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::createActions(void)
{
    //Settings menu actions
    this->inpFilePathAction = new QAction(tr("Set inp file output path"), this);
    this->octopusOutPathPutAction = new QAction(tr("Set Octopus output files path"), this);
    this->aboutAction = new QAction (tr("About"),this);
    this->settingAction = new QAction(tr("Settings"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));
    connect(settingAction,SIGNAL(triggered()),this,SLOT(settings()));

    //view menu actions
    this->toggleFullScreen = new QAction(QIcon(":/images/ok"), tr("Full Screen"), this);
    this->toggleFullScreen->setIconVisibleInMenu(true);
    this->toggleFullScreen->setCheckable(true);
    connect(toggleFullScreen, SIGNAL(triggered(bool)), this, SLOT(toggleFullScreenFunction(bool)));

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::createMenus(void)
{
    this->settingsMenu = menuBar()->addMenu(tr("&Settings"));
    settingsMenu->addAction(this->inpFilePathAction);
    settingsMenu->addAction(this->octopusOutPathPutAction);
    settingsMenu->addAction(this->settingAction);
    //view menu
    this->viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(this->toggleFullScreen);

    //about menu
    this->aboutMenu = menuBar()->addMenu(tr("&About"));    
    aboutMenu->addAction(this->aboutAction);

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::saveAllParameters(void)
{
    QDir dir(*inpFilePath);
    if(!multiDirectoriesCheckBox->isChecked()){

        if(!MainWindow::controlEmptyFields())
            return;

        setInpText(QString::number(staticMagneticFieldSpin->value()));

        QFile file(*inpFilePath+"/"+*inpFileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this,(tr("Error")),(tr("Sory! We have a problem. We couldn't create inp file.")));
            return;
        }

        qDebug() << QFileInfo(file).absoluteFilePath();
        QTextStream out(&file);
        out<<inpText;
        file.flush();
        file.close();
        QMessageBox::information(this,tr("File"),tr("inp file created succesfully."),QMessageBox::Ok);

    }else{
        if(!MainWindow::controlEmptyFields())
            return;
        double first = initialValueSpin->value();
        double last = lastValueSpin->value();
        double increase = increaseSpin->value();

        dir.mkdir("Extra States = "+extraStatesSpin->text());
        dir.cd("Extra States = "+extraStatesSpin->text());
        while(first<=last){
            QString tmppath= QString::number(first);

            dir.mkdir(tmppath);
            dir.cd(tmppath);

            QFile file(*inpFilePath+"/Extra States = "+extraStatesSpin->text()+"/"+tmppath +"/"+ *inpFileName);
            file.open(QIODevice::WriteOnly);
            QFileInfo info(*csvFilePath);
            QFile csvFile(*csvFilePath);
            csvFile.open(QIODevice::ReadOnly);

            setInpText(tmppath);
            qDebug() << QFileInfo(file).absoluteFilePath();
            csvFile.copy(*inpFilePath+"/Extra States = "+extraStatesSpin->text()+"/"+tmppath +"/"+info.fileName());
            QTextStream out(&file);
            out<<inpText;            

            file.flush();
            file.close();            
            csvFile.flush();
            csvFile.close();
            dir.cdUp();
            first+=increase;
        }
        QMessageBox::information(this,tr("Ok"),tr("Be relax! Everything is Ok. :))"));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////

bool MainWindow::controlEmptyFields(void)
{
    return true;
}


///////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::about(){
    QMessageBox::about(NULL,tr("About"),
                       tr("Version: 0.1\nUbuntu-tr.net - UGT\nFor Bugs and Questions \nSemetey Coskun -Programmer - semeteycoskun@gmail.com\nSinan Ates -Physicist, Programmer - sinanates2011@gmail.com"));
}


///////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleFullScreenFunction(bool isToggled)
{
    if(isToggled){
        this->showFullScreen();
        this->toggleFullScreen->setIcon(QIcon(":/images/cancel"));
    }
    else{
        this->showNormal();
        this->toggleFullScreen->setIcon(QIcon(":/images/ok"));
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::setInpText(QString magneticField)
{
    inpText ="Dimensions = ";         inpText+=dimensionSpin->text();
    inpText+="\n\nFlushMessages = ";    inpText+=flushMessagesCombo->currentText();
    int checkedCheckboxNumber = 0;
    int n=calculationModeQQueue.count();
    for(int i=0;i<n;++i){
        if(calculationModeQQueue[i]->isChecked())
            ++checkedCheckboxNumber;
    }
    if(checkedCheckboxNumber==1){
        inpText+="\n\nCalculationMode = ";
        for(int i=0;i<n;++i){
            if(calculationModeQQueue[i]->isChecked())
                inpText+=calculationModeQQueue[i]->text();
        }
    }
    if(checkedCheckboxNumber!=1){
        inpText+="\n\n%CalculationMode\n";
        for(int i=0,k=0;i<n;++i){
            if(calculationModeQQueue[i]->isChecked()){
                if(k!=0)
                    inpText+=" | ";
                ++k;
                inpText+=calculationModeQQueue[i]->text();
            }
        }
        inpText+="\n%";
    }
    inpText+="\n\nUnits = ";              inpText+=unitsCombo->currentText();
    inpText+="\n\nFromStrach = ";         inpText+=fromScratchCombo->currentText();
    inpText+="\n\nExtraStates = ";        inpText+=extraStatesSpin->text();
    inpText+="\n\nN = ";                  inpText+=NSpin->text();
    inpText+="\n\n%Species\n";
    inpText+='"'+speciesLineEdit1->text() +'"'+" | " + speciesSpin->text()+" | "+speciesCombo->currentText()+" | "
            +NSpin->text()+" | "+'"'+speciesLineEdit2->text()+'"';
    inpText+="\n%";
    inpText+="\n\n%Coordinates\n";
    inpText+='"'+coordinatesLineEdit->text()+'"'+" | "+coordinatesSpin1->text()+" | "+coordinatesSpin2->text()
            +" | "+coordinatesCombo->currentText();
    inpText+="\n%";
    inpText+="\n\n%Occupations\n";        inpText+=occupationsText->toPlainText();
    inpText+="\n%";
    inpText+="\n\nSpinComponents = ";     inpText+=spinComponentsCombo->currentText();
    inpText+="\n\nP_c = ";                inpText+=QString::number( p_cDoubleSpin->value());
    inpText+="\n\n%StaticMagneticField\n";inpText+=staticMagneticFieldSpin1->text()+" | "+
            staticMagneticFieldSpin2->text()+" | 0.1457106*P_c*"+magneticField;
    inpText+="\n%";
    inpText+="\n\nBoxShape = ";           inpText+=boxShapeCombo->currentText();
    inpText+="\n\n%LSize\n";              inpText+=lSizeSpin1->text()+"|"+lSizeSpin2->text()+"|"+lSizeSpin3->text();
    inpText+="\n\n%";
    inpText+="\n\nSpacing = ";            inpText+=QString::number(spacingDoubleSpin->value());
    inpText+="\n\nDerivativesOrder = ";   inpText+=derivativesOrderCombo->currentText();
    inpText+="\n\nGyroMagneticRatio = ";  inpText+=gyroMagneticRatioSpin->text();
    inpText+="\n\nLCAOStart = ";          inpText+=LCAOStarCombo->currentText();
    inpText+="\n\nTheoryLevel = ";        inpText+=theoryLevelCombo->currentText();
    inpText+="\n\nEigenSolver = ";        inpText+=eigenSolverCombo->currentText();
    inpText+="\n\nMaximumIlter = ";       inpText+=maximumIterSpin->text();
    inpText+="\n\nConvAbsEv = ";          inpText+=convAbsEvSpin->text();
    inpText+="\n\nTypeOfMixing = ";       inpText+=typeOfMixingCombo->currentText();
    inpText+="\n\nMixing = ";             inpText+=QString::number(mixingDoubleSpin->value());
    inpText+="\n\nParallelizationStrategy = ";    inpText+=parallelizationStrategyCombo->currentText();
    inpText+="\n\nOutput = ";
      n=outputQQueue.count();
      for(int i=0,k=0;i<n;++i){
          if(outputQQueue[i]->isChecked()){
                if(k!=0)
                    inpText+=" + ";
                ++k;
                inpText+= outputQQueue[i]->text();
          }
      }
      inpText+="\n\nOutputMatrixElements = ";
      n=outputMatrixElementsQQueue.count();
      for(int i=0,k=0;i<n;++i){
          if(outputMatrixElementsQQueue[i]->isChecked()){
                if(k!=0)
                    inpText+=" + ";
                ++k;
                inpText+= outputMatrixElementsQQueue[i]->text();
          }
      }
      inpText+="\n\nOutputHow = ";
      n=outputHowQQueue.count();
      for(int i=0,k=0;i<n;++i){
          if(outputHowQQueue[i]->isChecked()){
                if(k!=0)
                    inpText+=" + ";
                ++k;
                inpText+= outputHowQQueue[i]->text();
          }
      }

}
void MainWindow::workWithMultiDirectories(int state)
{
    if(state!=0){
        initialValueSpin->setEnabled(true);
        lastValueSpin->setEnabled(true);
        increaseSpin->setEnabled(true);
        staticMagneticFieldSpin->setEnabled(false);
    }
    else{
        initialValueSpin->setEnabled(false);
        lastValueSpin->setEnabled(false);
        increaseSpin->setEnabled(false);
        staticMagneticFieldSpin->setEnabled(true);
    }
}
void MainWindow::setInpFilePath()
{
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    *inpFilePath = QFileDialog::getExistingDirectory(this,
                                tr("Inp File Directory"),
                                *inpFilePath,
                                options);
    inpFilePathLine->setText(*inpFilePath);
}
void MainWindow::setCsvFilePath()
{
    QFileDialog::Options options;
    QString selectedFilter;
    *csvFilePath = QFileDialog::getOpenFileName(this,
                                                tr(".csv File"),
                                                *csvFilePath,
                                                tr("All Files (*);;csv File (*.csv)"),
                                                &selectedFilter,
                                                options);
    csvFilePathLine->setText(*csvFilePath);
}
/////////////////////////////////
void MainWindow::keyReleaseEvent(QKeyEvent* event)
{

    switch(event->key()){
        case Qt::Key_F11:{
            const bool currentState = this->isFullScreen();
            toggleFullScreenFunction(!currentState);
        }
    }
}
void MainWindow::settings()
{
    settingsDialog = new SettingDialog;
    if(settingsDialog->exec()== QDialog::Accepted){

    }
}


