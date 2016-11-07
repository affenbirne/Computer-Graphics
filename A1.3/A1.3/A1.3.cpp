// A1.3.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
/*
Command-Line in VS2015 Building tools:
/GS /GL /analyze- /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /Fd"Release\vc140.pdb" /Zc:inline /fp:precise /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oy- /Oi /MD /Fa"Release\" /EHsc /nologo /Fo"Release\" /Fp"Release\A1.3.pch"
Linker:
/OUT:".\Release\A1.3.exe" /MANIFEST /LTCG:incremental /NXCOMPAT /PDB:".\Release\A1.3.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /MACHINE:X86 /OPT:REF /SAFESEH /INCREMENTAL:NO /PGD:".\Release\A1.3.pgd" /SUBSYSTEM:CONSOLE /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /ManifestFile:"Release\A1.3.exe.intermediate.manifest" /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1
*/

#include "Mesh.h"
#include "SceneManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& os, const Vector& vector)
{
	os << vector.x << " " << vector.y << " " << vector.z;
	return os;
};

ostream& operator<<(ostream& os, const Mesh& mesh)
{
	os << mesh.id << " " << mesh.name << " " << mesh.faces << " " << mesh.vertices << " " << mesh.scaling << " " << mesh.center;
	return os;
};

istream& operator >> (istream& is, Vector& vector)
{
	is >> vector.x;
	is >> vector.y;
	is >> vector.z;

	return is;
};

istream& operator >> (istream& is, Mesh& mesh)
{
	is >> mesh.id >> mesh.name >> mesh.faces >> mesh.vertices >> mesh.scaling >> mesh.center;

	return is;
};


void save_to_file(SceneManager& manager)
{
	ofstream file;
	file.open("objects.txt");

	for (auto it = manager.meshs.begin(); it != manager.meshs.end(); ++it)
	{
		file << *it << endl;
	}

	file.close();

}

void load_from_file(SceneManager& manager)
{
	string line;
	ifstream objects("objects.txt");

	if (objects.is_open())
	{
		while (getline(objects, line))
		{
			Mesh mesh;
			istringstream iss;
			iss.str(line);
			iss >> mesh;
			manager.add_mesh(mesh);
		}
		objects.close();
	}
}

void list_mesh(SceneManager& manager)
{
	for (Mesh& mesh : manager.meshs)
	{
		cout << mesh.to_string() << endl;
	}
}

void remove_mesh(SceneManager& manager)
{
	bool delete_process = true;

	cout << "If you want to delete by ID press i and ENTER" << endl;
	cout << "If you don't want to delete a mesh press e and ENTER" << endl;

	while (delete_process)
	{
		switch (cin.get())
		{
		case 'e':
			cout << "Abort deleting" << endl;
			delete_process = false;
			break;
		case 'i':
			int id;
			cout << "Please enter ID and ENTER" << endl;
			cin >> id;
			manager.delete_mesh(id);
			cout << "Your mesh was successfully deleted" << endl;
			delete_process = false;
			break;
		}
	}
}
void enter_mesh(SceneManager& manager)
{
	string name;
	int faces;
	int vertices;
	float scaling;
	Vector center;

	cout << "Enter a name for your mesh: " << endl;
	cin >> name;

	cout << "Enter number of vertices of your mesh: " << endl;
	cin >> vertices;

	cout << "Enter number of faces of your mesh: " << endl;
	cin >> faces;

	cout << "Enter scaling of your mesh: " << endl;
	cin >> scaling;

	cout << "Enter x-coordinate of the center of your mesh: " << endl;
	cin >> center.x;

	cout << "Enter y-coordinate of the center of your mesh: " << endl;
	cin >> center.y;

	cout << "Enter z-coordinate of the center of your mesh: " << endl;
	cin >> center.z;

	Mesh mesh(name, vertices, faces, scaling, center);
	manager.add_mesh(mesh);

	cout << "Your Mesh was successfully created and added to your scene" << endl;

}

int main()
{
	SceneManager manager;
	load_from_file(manager);

	bool run = true;
	cout << "For creating a new mesh press m and ENTER." << endl;
	cout << "For listing all meshs in ascending order press l and ENTER." << endl;
	cout << "For removing a mesh press r and ENTER." << endl;
	cout << "For exiting press e and ENTER. All meshes will be saved to objects.txt" << endl;
	while (run)
	{
		switch (cin.get())
		{
		case 'e':
			save_to_file(manager);
			run = false;
			break;

		case 'm':
			enter_mesh(manager);
			break;

		case 'l':
			list_mesh(manager);
			break;
		case 'r':
			remove_mesh(manager);
			break;
		}
	}
	return 0;
}

