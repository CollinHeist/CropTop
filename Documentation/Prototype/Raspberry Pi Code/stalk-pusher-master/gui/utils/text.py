"""
---
Abbreviations
s: singleline / m: multiline (which means single or multi)
p: predefined font size / d: dynamic font size
t: truncated / u: untruncated
a: automatic line switch / e: explicit line switch
---
Conventions
pos = [x, y] -> x: x center of bbounding rect, y: y center of bounding rect
dim: = [xdim, ydim] -> xdim: bounding rect width, ydim: bounding rect height
---
Types of font rendering:
- spu
    *s
    *p
    *u
    *defined by x, y, font
    *used in default
- spt
    *s
    *p
    *t with ".." to fit box
    *defined by x, y, font, xdim
    *used in notelists

- mpue
    *m
    *p,
    *u
    *e
    *defined by x, y, font, ydim
    *used in Buttons

- mpta
    *m
    *p
    *t to fit box
    *a
    *defined by x, y, fontSize, xdim, ydim
    *used in Message bodies
- mpte
    *m
    *p
    *t with '..' to fit box
    *e
    *defined by x, y, fontSize, xdim, ydim
    *used in Message bodies

- sdu
    *s
    *d
    *u
    *defined by x, y, xim, ydim
    *used in 

"""
import pygame as pg
import defs as d
# fontCol = (255,255,255)
# fontType = 'Arial'
# fontSize = 30
# font = pg.font.SysFont(fontType, fontSize)

# def text(text, coords, disp):
#     global font, fontCol
#     print(fontCol)
#     txt = font.render(text, True, fontCol)
#     disp.blit(txt, (txt.get_rect(center=coords)))
# def fontCol(col):
#     global fontCol
#     fontCol = col
# def setFont(fontT):
#     global font, fontType, fontSize
#     fontType = fontT
#     font = pg.font.SysFont(fontType, fontSize)
# def fontS(fontS):
#     global font, fontType, fontSize
#     if int(fontS) != fontSize:
#         fontSize = int(fontS)
#         font = pg.font.SysFont(fontType, fontSize)
############################################################
############################################################
############################################################




def spu(disp, text, pos, font, fontCol = d.font_col_d, bold = True):
    txtObj = font.render(text, bold, fontCol)
    disp.blit(txtObj, txtObj.get_rect(center=pos))

def spt(disp, text, pos, width, font, fontCol = d.font_col_d, bold = True):
    xFit = font.size(text)[0] <= width           
    if not xFit:
        text = text + '..'
        
    while not xFit:
        fontWidth = font.size(text)[0]
        if fontWidth > width:
            text = text[:-3] + '..'
        else:
            xFit = True
    
    txtObj = font.render(text, bold, fontCol)
    disp.blit(txtObj, txtObj.get_rect(center=pos))


def mpue(disp, text, pos, height, font, fontCol = d.font_col_d, bold = True):
        textRows = text.splitlines()
        numRows = len(textRows)        
        for i in range(numRows):
            x = pos[0]
            y = pos[1] - height/2 + (i+1)*height/(numRows+1)
            txtObj = font.render(textRows[i], bold, fontCol)
            disp.blit(txtObj, txtObj.get_rect(center=(x, y))) 
            
def mpte(disp, text, pos, dim, font, fontCol = d.font_col_d, bold = True):
        textRows = text.splitlines()
        numRows = len(textRows)        
        for i in range(numRows):
            x = pos[0]
            y = pos[1] - dim[1]/2 + (i+1)*dim[1]/(numRows+1)
            spt(disp, textRows[i], (x, y), dim[0], font, fontCol, bold)
#             txtObj = font.render(textRows[i], bold, fontCol)
#             disp.blit(txtObj, txtObj.get_rect(center=(x, y)))    
   
'''
mpta is a modified version of function provided below:
http://pygame.org/wiki/TextWrap
'''     
# draw some text into an area of a surface
# automatically wraps words
# returns any text that didn't get blitted
def mpta(disp, text, pos, dim, font, fontCol = d.font_col_d):
    #account for different positioning convention
    pos = (pos[0]-dim[0]/2, pos[1]-dim[1]/2)

    rect = pg.Rect(pos, dim)
    y = rect.top
    lineSpacing = -2

    # get the height of the font
    fontHeight = font.size("Tg")[1]
    
    texts = text.splitlines()
    for textLine in texts:
        while textLine:
            i = 1
    
            # determine if the row of text will be outside our area
            if y + fontHeight > rect.bottom:
                break
    
            # determine maximum width of line
            while font.size(textLine[:i])[0] < rect.width and i < len(textLine):
                i += 1
    
            # if we've wrapped the text, then adjust the wrap to the last word      
            if i < len(textLine): 
                i = textLine.rfind(" ", 0, i) + 1
    
            # render the line and blit it to the surface
            image = font.render(textLine[:i], True, fontCol)
    
            disp.blit(image, (rect.left, y))
            y += fontHeight + lineSpacing
    
            # remove the text we just blitted
            textLine = textLine[i:]

def sdu():
    pass            
###############################################################################
###############################################################################
###############################################################################

# '''
# multilineText is a modified version of function provided below:
# https://stackoverflow.com/a/42015050/3000014
# '''     
# def multilineText(disp, text, pos, dim, font, color=fontCol):
#     words = [word.split(' ') for word in text.splitlines()]  # 2D array where each row is a list of words.
#     space = font.size(' ')[0]  # The width of a space.
#     max_width = dim[0]*2
#     max_height = dim[1]#surface.get_size()
#     x, y = pos
#     for line in words:
#         for word in line:
#             word_surface = font.render(word, 1, color)
#             word_width, word_height = word_surface.get_size()
#             if x + word_width >= max_width:
#                 x = pos[0]  # Reset the x.
#                 y += word_height  # Start on new row.
#             disp.blit(word_surface, (x, y))
#             x += word_width + space
#         x = pos[0]  # Reset the x.
#         y += word_height  # Start on new row.
  
  # def findInclString(str, fontType, width, height, fontSize = None, maxFontSize = 5*d.px):
#     if fontSize is None:
#         fontSize = 0.5*d.px
#         maxFontFound = False
#     else:
#         maxFontFound = True
#         
#     maxWidth = 0.95*width
#     maxHeight = 0.95*height
#     
#     font = pg.font.SysFont(fontType, int(fontSize))
#     fontWidth, fontHeight = font.size(str)
#     
#     while not maxFontFound:
#         if fontHeight < maxHeight and fontSize < maxFontSize:
#             fontSize += 0.2*d.px
#         else:
#             fontSize -= 0.2*d.px
#             maxFontFound = True
#         font = pg.font.SysFont(fontType, int(fontSize))
#         fontWidth, fontHeight = font.size(str)
# 
#     ###shrink string so it fits in box with two dots
#     if fontWidth <= maxWidth:
#         return (str, int(fontSize))
#     
#     str = str + '..'
#     xFit = False
#     
#     while not xFit:
#         font = pg.font.SysFont(fontType, int(fontSize))
#         fontWidth, fontHeight = font.size(str)
#         if fontWidth > maxWidth:
#             str = str[:-3] + '..'
#         else:
#             xFit = True
#     return (str, int(fontSize))

# def findFontSize(str, fontType, width, height, maxFontSize = 5*d.px):
#     fontSize = 2*d.px
#     maxWidth = 0.95*width
#     maxHeight = 0.95*height
#     while True:
#         font = pg.font.SysFont(fontType, int(fontSize))
#         fontWidth, fontHeight = font.size(str)
#         if fontWidth < maxWidth and fontHeight < maxHeight and fontSize < maxFontSize:
#             fontSize += 0.2*d.px
#         else:
#             fontSize -= 0.2*d.px
#             break
#     return int(fontSize)

