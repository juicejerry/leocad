#ifndef _LC_APPLICATION_H_
#define _LC_APPLICATION_H_

#include "lc_array.h"

class Project;
class lcPiecesLibrary;
enum lcLightingMode : int;

class lcPreferences
{
public:
	void LoadDefaults();
	void SaveDefaults();

	int mMouseSensitivity;
	lcLightingMode mLightingMode;
	bool mDrawAxes;
	bool mDrawEdgeLines;
	float mLineWidth;
	bool mDrawGridStuds;
	lcuint32 mGridStudColor;
	bool mDrawGridLines;
	int mGridLineSpacing;
	lcuint32 mGridLineColor;
	bool mFixedAxes;
};

class lcApplication
{
	Q_DECLARE_TR_FUNCTIONS(lcApplication);

public:
	lcApplication();
	~lcApplication();

	void SetProject(Project* Project);
	bool Initialize(int argc, char *argv[], const char* LibraryInstallPath, const char* LDrawPath, bool& ShowWindow);
	void Shutdown();
	void ShowPreferencesDialog();

	bool LoadPiecesLibrary(const char* LibPath, const char* LibraryInstallPath, const char* LDrawPath);

	void SetClipboard(const QByteArray& Clipboard);
	void ExportClipboard(const QByteArray& Clipboard);

	Project* mProject;
	lcPiecesLibrary* mLibrary;
	lcPreferences mPreferences;
	QByteArray mClipboard;

protected:
	void ParseIntegerArgument(int* CurArg, int argc, char* argv[], int* Value);
	void ParseStringArgument(int* CurArg, int argc, char* argv[], char** Value);
};

extern lcApplication* g_App;

inline lcPiecesLibrary* lcGetPiecesLibrary()
{
	return g_App->mLibrary;
}

inline Project* lcGetActiveProject()
{
	return g_App->mProject;
}

inline lcPreferences& lcGetPreferences()
{
	return g_App->mPreferences;
}

#endif // _LC_APPLICATION_H_
