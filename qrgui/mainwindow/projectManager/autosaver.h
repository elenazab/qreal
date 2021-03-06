#pragma once
#include <QtCore/QObject>
#include <QtCore/QTimer>

namespace qReal {

class ProjectManager;

/**
 * @brief class provides automatic saving of the project at equal time intervals.
 * All options for working are retrieved from the settings manager.
 *
 * Autosaver provides an interface that allows you to make it reload parameters
 */
class Autosaver : public QObject
{
	Q_OBJECT

public:
	explicit Autosaver(ProjectManager *projectManager);
	void reinit();

	// if option AutosaveInterval in not specified

private slots:
	void save();

private:
	uint interval();
	QString filePath();

	static uint const defaultInterval = 600;

	ProjectManager *mProjectManager;
	QTimer *mTimer;
};

}
