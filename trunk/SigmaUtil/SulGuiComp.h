// SulGuiComp.h

#ifndef SULGUICOMP_H__
#define SULGUICOMP_H__

#include "SulString.h"
#include "SulGeomQuad.h"
#include "SulSigSlots.h"
#include "SulGuiThemeXml.h"
#include "SulSigSlots.h"
#include "SulExport.h"
#include <osg/matrixtransform>
#include <osg/geode>
#include <stack>

class SUL_EXPORT CSulGuiComp : public osg::MatrixTransform, public sigma::has_slots<>
{
public:
					CSulGuiComp( const CSulString& sCompName );
					CSulGuiComp( const CSulString& sCompName, float x, float y );

	// must be called after all setups have been called
	virtual void	init();

	virtual void	setEditMode( bool bEdit );
	bool			isEditMode();

	// active buttons can still be moved and clicked on, but depending on the component it should limit what is active
	void			setActive( bool bActive );
	bool			isActive();

	virtual void	setupAttr( CSulXmlAttr* pAttr );
	virtual void	setupTheme( CSulGuiThemeXml* pThemeXml );
	virtual void	setupEventHandler( class CSulGuiEventHandler* pEventHandler );
	virtual void	setupView( float w, float h );

	void			setXY( float x, float y );
	void			setX( float x );
	void			setY( float y );
	float			getX();
	float			getY();
	float			getWorldX();
	float			getWorldY();

	// attribute x and y values (they never change)
	float			getAttrX();
	float			getAttrY();

	virtual void	show( bool bShow );
	virtual void	toggleShow();

	void			setLayer( sigma::uint32 layer );

	virtual void	eventMouseMove( float local_x, float local_y, float x, float y );
	virtual void	eventMouseDrag( float local_x, float local_y, float x, float y );
	virtual void	eventMousePushed( float local_x, float local_y, float x, float y );
	virtual void	eventMouseRelease( float x_local, float y_local, float x, float y );
	virtual void	eventKeyDown( sigma::int32 key, sigma::int32 iMod );

	CSulString						getThemeValue( const CSulString& attr );
	CSulGuiEventHandler*			getEventHandler();
	osg::Vec2						getNativeDimensions();
	const CSulString&				getId() const;

	virtual class CSulGuiCanvas*	asCanvas()	{ return 0; }
	virtual class CSulGuiTextBox*	asTextBox() { return 0; }
	virtual class CSulGuiListBox*	asListBox() { return 0; }
	virtual class CSulGuiButton*	asButton()	{ return 0; }

	sigma::signal2<float, float>	signalPositionChanged;

private:
	void			initConstructor();

	void			onNativeDimensionsChanged( float w, float h );

private:
	class CSulGuiEventHandler*		m_pEventHandler;
	bool							m_bActive;
	osg::ref_ptr<CSulGuiThemeXml>	m_rThemeXml;
	CSulString						m_sCompName;
	osg::Vec2						m_nativeDimensions;
	CSulString						m_id;

	bool							m_bEditMode;

	sigma::uint32					m_renderbinNum;

	float							m_attrX;			
	float							m_attrY;	
	bool							m_attrValid;
};

typedef std::vector< osg::ref_ptr<CSulGuiComp > >	VEC_GUICOMP;
typedef std::stack< osg::ref_ptr<CSulGuiComp > >	STACK_GUICOMP;

#endif // SULGUICOMP_H__