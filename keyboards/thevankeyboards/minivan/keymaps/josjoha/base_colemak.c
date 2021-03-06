/*
 * License (GPL):
  
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * Author: © 2020 by Jos Boersema
 *
 */

// --------------------------------------v---------------------------------------
//                                 Configuration:
// --------------------------------------v---------------------------------------

// --------------------------------------^---------------------------------------
//            Below here no more comfortable configuration options.....
// --------------------------------------^---------------------------------------


        /*                            Redefine a layer in this file
         *
         * _Activate_ one or more of the below BASESFILE_LAYER_..., to redefine the layer
         * in this file. The version in ./keymap.c will be ignored. Keep in mind to use
         * transparent keys (_______) for “hold” layer switch keys on the BASE map, for
         * your new layer.
         */
// #define BASESFILE_LAYER_ACC 
// #define BASESFILE_LAYER_DRA 
// #define BASESFILE_LAYER_BON 
// #define BASESFILE_LAYER_PAD 
// #define BASESFILE_LAYER_MOV 
// #define BASESFILE_LAYER_RAR 
// #define BASESFILE_LAYER_FUN 

        /*  ⬇ */

    /* Layer _..._BASE: Qwerty, normal BASE layer and 'default' layer
     *
     * - Dual use keys create a delay in the key (tap/hold keys), therefore
     *   space is not dual use (most ued key), neither is hyphen.
     */ 

// Process user configuration wrt ‛Default’ or ‛Alternative’ spot for this layout.
# if   defined(BASE_COLEMAK__DEF_BASE)
    [ _DEF_BASE ] = LAYOUT_redefined (
# elif defined(BASE_COLEMAK__ALT_BASE)
    [ _ALT_BASE ] = LAYOUT_redefined (
# endif

/*
     Layer _..._BASE (Letters). This is Colemak, except backspace/tab 
                                                  | Right hand
         <pink2     <pinky<ring <middl<index<indx2| indx2>index>middl>ring> pinky>pinky2>   // Keys by finger
         -o-                                     <|>                                    ... //-o- BASE access
         Esc        qQ    wW    fF    pP    gG    | jJ    lL    uU    yY    ;:         Bksp
         Tab+LCtl   aA    rR    sS    tT    dD    | hH    nN    eE    iI    oO           '"
         LSht+_PAD  zZ    xX    cC    vV    bB    | kK    mM    ,<    .>    /?    RSht+_FUN 
             +_MOV⁵                               |                                   +_RAR⁶
     ---------------------------------------------------------------------------------------
     Left+LAlt Del;_ACC _..._NSY(_DRA)  Enter+_MOV| Space  _..._NSY(_DRA) LGUI    Right;_RAR 
               hold     hold₍₁,₂٭₎      hold      |        hold₍₁,₂٭₎             hold     // switch type
               hold₍₂₎  ^-┃-----------------------+--------^ ┃                          // ₁₎ both = _DRA
               ┗━━━_BON━━━╋┅───────────┄┄┄«or»┄┄┄─+─────────┅┛                          // ₂₎ both = _BON
     <1   ±    <2       <3              <4        | 4>     3>             2>   ±  1>    // Keys by number
          ^³                                                                   ^⁴   // Optional more keys
        (RGUI)                                                               (_MOV)

     ₁) Dual hold for _DRA, single hold for _..._NSY. Marked by: ^--…--^
     ₂) Hold key “<2” with either٭ key “<3” or “3>” for _BON, single hold “<2” for _ACC. Marked: ┗━━…━━┛
     ₃) 'South paw' hardware configuration. Configurable, default shown.
     ₄) 'Arrow' hardware configuration  Configurable, default shown.
     ₃ ₄) There are two more optional hardware keys, to make it easier to compile for
          a 12x12x12x11 or 12x12x12x12 layouts.
     ₅) Left Shift when pressed with another key. Medium long: to toggle _PAD. Long: toggle _MOV.
     ₆) Right shift when pressed with another key. medium long: to toggle _FUN. Long: toggle _RAR.
*/
//
//      <pink2            , <pink, <ring, <midd, <indx, <ind|, indx>, inde>, midd>   , ring>  , pink>   , pink2>        ,
//      -*!-              ,      ,      ,      ,      ,    <|,>     ,      ,         ,        ,         ,               ,
        KC_ESC            , KC_Q , KC_W , KC_F , KC_P , KC_G , KC_J , KC_L , KC_U    , KC_Y   , KC_SCLN , KC_BSPC       ,
        LCTL_T ( KC_TAB ) , KC_A , KC_R , KC_S , KC_T , KC_D , KC_H , KC_N , KC_E    , KC_I   , KC_O    , KC_QUOT       ,
        CHOLTAP_LSHFT     , KC_Z , KC_X , KC_C , KC_V , KC_B , KC_K , KC_M , KC_COMM , KC_DOT , KC_SLSH , CHOLTAP_RSHFT ,
//      -----------------------------------------------------------------------------------------------------------------
        LALT_T ( KC_LEFT ) 

# ifdef TRANSMINIVAN_LEFTSIDE
                           , MO ( _PAD )
# endif

# ifdef MORE_KEY__COMMAND
                           , MORE_key1_BASE
# endif

# ifdef SWITCH_HOLD_ACC_NSY 
                           , DUO_HOLD , CHOLTAP_ACCE 
# else
                           , CHOLTAP_ACCE , DUO_HOLD
# endif
                                                     , LT__MOV__KC_ENT

#     ifdef TRANSMINIVAN_MIDLEFT
                                                     , TRANS_MIDLEFT
#     endif

                                                                       , KC_SPC , DUO_HOLD , KC__YGUI

# ifdef TRANSMINIVAN_RIGHTSIDE
                                                                                                      , MO ( _FUN )
# endif

# ifdef MORE_KEY__ARROW
                                                                                                      , MORE_key2  
# endif

                                                                                                      , CHOLTAP_LAYR
//                         ,              ,          ,               <|,>       ,          ,          ,
//      <1           ±  ±  , <2           , <3       , <4             |, 4>     , 3>       , 2>       , ±  ±  1>

                      ),

        /* ⬆⬇ */

    /* Layer _..._NSY: Numbers and symbols, to work with the Colemak base layer above (unchanged from Qwerty).
     *          Off hand Number input (-.Bksp ent (shft)tab).
     */
    // KC_TILD does not work there, because of a limitation with shifted keys (nov 2019).

// Process user configuration wrt ‛Default’ or ‛Alternative’ spot for this layout.
# if   defined(BASE_COLEMAK__DEF_BASE)
    [ _DEF_NSY ] = LAYOUT_redefined (
# elif defined(BASE_COLEMAK__ALT_BASE)
    [ _ALT_NSY ] = LAYOUT_redefined (
# endif

/*
     Layer _..._NSY (Numbers and SYmbols). This fits the above Colemak layer _..._BASE
    
     <pink2   <pinky<ring <middl<index<indx2| indx2>index>middl>ring>pin>pink2>
              -*-                          <|>                                  //(toggle) Access on _FUN
     BASE     !     @     #     $     %     | ^     &     *     (    )       Del
     Tab+LCtl 1!    2@    3#    4$    5%    | 6^    7&    8*    9(   0)  `~+RCtl
     -+LSht   [{    ]}    -_    \|    =+    | +     |     _     {     }  `~+RSht // limitation prevents ~
                          ^^                              ^  // Only differences with normal version _..._NSY
     ---------------------------------------------------------------------------
     Left+LAlt ___   ___   Ent  | .   ___   LGUI  Right+RAlt
                     -*-       <|>    -*-                                         //(hold) Access on _..._BASE
       <1   ±  <2    <3    <4   | 4>  3>    2>  ± 1>  
            ^                                   ^
          (RGUI)                              (_MOV)
*/
//
//
//      <pink2             , <pinky  , <ring   , <middl  , <index  , <indx2 |, indx2>  , index>  , middl>  , ring>   , pinky>  , pink2>             ,
//                         , -*-     ,         ,         ,         ,       <|,>        ,         ,         ,         ,         ,                    ,
        CTO_BASE           , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL             ,
        LCTL_T ( KC_TAB )  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , RCTL_T ( KC_GRV )  , 
        LSFT_T ( KC_MINS ) , KC_LBRC , KC_RBRC , KC_MINS , KC_BSLS , KC_EQL  , KC_PLUS , KC_PIPE , KC_UNDS , KC_LCBR , KC_RCBR , RSFT_T ( KC_TILD ) ,  
//      ---------------------------------------------------------------------------------------------------------------------------------------------
        LALT_T ( KC_LEFT ) 

# ifdef TRANSMINIVAN_LEFTSIDE
                           , XXXXXXX
# endif

# ifdef MORE_KEY__COMMAND
                           , MORE_key1  
# endif

                           , _______ , _______ , KC_ENT 

# ifdef TRANSMINIVAN_MIDLEFT
                                               , TRANS_MIDLEFT  
# endif

                                                               , KC_DOT , DUO_HOLD , KC__YGUI
                                                             
# ifdef TRANSMINIVAN_RIGHTSIDE                               
                                                                                              , XXXXXXX
# endif                                                      
                                                             
# ifdef MORE_KEY__ARROW                                      
                                                                                              , MORE_key2  
# endif                                                      
                                                             
                                                                                              , RALT_T ( KC_RGHT )
//                         ,         , -*-     ,             <|,>       , -*-      ,          ,
//      <1           ±  ±  , <2      , <3      , <4           |, 4>     , 3>       , 2>       , ±  ±  1>

                      ),

        /* ⬆⬇ */
