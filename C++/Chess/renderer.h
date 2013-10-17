#ifndef RENDERER
#define RENDERER

class Renderer
{
public:
    virtual void DrawField(Field& field) = 0;
    virtual void DrawFigure(Figure* figure) = 0;
};

#endif // RENDERER
