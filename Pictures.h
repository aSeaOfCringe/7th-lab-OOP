#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Resources;

ref class Pictures {
private:
	static Bitmap^ LoadBitmap(String^ bitmapName) {
		ResourceManager^ resman = gcnew ResourceManager("PopBallGame.Pictures", Reflection::Assembly::GetExecutingAssembly());
		return (Bitmap^)resman->GetObject(bitmapName);
	}
public:
	static Bitmap^ background = LoadBitmap("background");
	static Bitmap^ building1 = LoadBitmap("building1");
	static Bitmap^ building2 = LoadBitmap("building2");
	static Bitmap^ building3 = LoadBitmap("building3");
	static Bitmap^ hunter1 = LoadBitmap("soldier1");
	static Bitmap^ hunter2 = LoadBitmap("soldier2");
	static Bitmap^ hunter3 = LoadBitmap("hunter3");
	static Bitmap^ zombie1 = LoadBitmap("zombie1");
	static Bitmap^ zombie2 = LoadBitmap("zombie5");
	static Bitmap^ zombie3 = LoadBitmap("zombie6");
	static Bitmap^ zombie4 = LoadBitmap("zombie7");
	static Bitmap^ zombie5 = LoadBitmap("zombie8");
	static Bitmap^ rip = LoadBitmap("rip");
};
