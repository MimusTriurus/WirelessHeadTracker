TEMPLATE = subdirs
SUBDIRS += \
    Transmitter \
    Receiver \
    TestUnityHeadTrackerLib

equals(QT_ARCH, arm) {
SUBDIRS += \
    SensehatSensorsGrabber
}
