# YkJpeg

Group: `Yk` (by the file name only). Source: `sdk/tree_src/YkJpeg.cpp`.

16 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `YkJpeg::InitTables` | 0x101CF870 | 393 | yes | - | Writes the JPEG encoder's standard tables to the output. (reviewed as game_101CF870) | medium |
| `YkJpeg::CopyBlock` | 0x101CFDB0 | 97 | yes | - | Copies a 16 by 16 block of pixels, clipped to the image. (reviewed as game_101CFDB0) | medium |
| `YkJpeg::Unpack565` | 0x101CFE20 | 132 | yes | - | Expands a 16-bit 5-6-5 colour into 8-bit components. (reviewed as game_101CFE20) | medium |
| `YkJpeg::UnpackBlock565` | 0x101CFEB0 | 167 | yes | - | Expands a block of 16-bit colours into 8-bit components. (reviewed as game_101CFEB0) | low |
| `YkJpeg::ForwardDct` | 0x101CFF60 | 579 | yes | - | Applies a forward 8 by 8 discrete cosine transform in integer arithmetic. (reviewed as game_101CFF60) | medium |
| `YkJpeg::EncodeBlock` | 0x101D0210 | 350 | yes | - | Entropy-codes one 8 by 8 block of coefficients. (reviewed as game_101D0210) | medium |
| `YkJpeg::Encode` | 0x101D0370 | 615 | yes | - | Encodes an image as a JPEG into an in-memory buffer. (reviewed as game_101D0370) | medium |
| `YkJpeg::GetCopyrightString` | 0x101D05E0 | 29 | yes | - | Returns the copyright string written into the JPEG. (reviewed as game_101D05E0) | medium |
| `YkJpeg::EncodeChecked` | 0x101D0600 | 51 | yes | - | Encodes an image and releases the encoder when the encode reports failure. (reviewed as game_101D0600) | low |
| `YkJpeg::Destructor` | 0x101D08C0 | 16 | yes | - | Destroys a YkJpeg encoder's buffers. (reviewed as game_101D08C0) | medium |
| `YkJpeg::Release` | 0x101D08D0 | 11 | yes | - | Releases a YkJpeg encoder's output buffer. (reviewed as game_101D08D0) | low |
| `YkJpeg::PutBit` | 0x101D0910 | 92 | yes | - | Writes one bit to the JPEG output, stuffing a zero byte after 0xFF. (reviewed as game_101D0910) | medium |
| `YkJpeg::PutBits` | 0x101D0970 | 72 | yes | - | Writes a code of the given length to the JPEG output, high bit first. (reviewed as game_101D0970) | medium |
| `YkJpeg::PutBytes` | 0x101D09E0 | 56 | yes | - | Writes raw bytes to the JPEG output buffer. (reviewed as game_101D09E0) | medium |
| `YkJpeg::FlushBits` | 0x101D0A60 | 59 | yes | - | Pads the partial byte with one bits and writes it out. (reviewed as game_101D0A60) | medium |
| `YkJpeg::CaptureAndEncode` | 0x101D1060 | 85 | yes | 2 | Captures a width x height image and encodes it as a JPEG. (reviewed as game_101D1060) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `YkJpeg::InitTables` calls `JpegTables_BuildCodeTable`, `JpegScreenshot_PutFFThenByte`, `JpegScreenshot_PutWordBE`, `JpegScreenshot_PutByte`, `YkJpeg::PutBytes`
- `YkJpeg::CopyBlock` calls nothing directly
- `YkJpeg::Unpack565` calls nothing directly
- `YkJpeg::UnpackBlock565` calls `YkJpeg::Unpack565`
- `YkJpeg::ForwardDct` calls nothing directly
- `YkJpeg::EncodeBlock` calls `YkJpeg::PutBits`
- `YkJpeg::Encode` calls `JpegTables_Free`, `JpegTables_Reset`, `Allocator_Generic`, `Mem_AllocDefault`, `YkJpgBit::Init`, `YkJpeg::PutBytes`, `JpegScreenshot_PutWordBE`, `JpegScreenshot_PutFFThenByte`, `YkJpeg::GetCopyrightString`, `JpegTables_BuildTables`, `YkJpeg::InitTables`, `YkJpeg::UnpackBlock565`, `YkJpeg::CopyBlock`, `game_101CFA00`, `YkJpeg::ForwardDct`, `game_101D01B0`, `YkJpeg::EncodeBlock`, `YkJpeg::FlushBits`
- `YkJpeg::GetCopyrightString` calls `YkCommon_GetOffset`, `game_10311FF1`
- `YkJpeg::EncodeChecked` calls `YkJpeg::Encode`, `JpegTables_Free`
- `YkJpeg::Destructor` calls `JpegTables_Reset`
- `YkJpeg::Release` calls `JpegTables_Free`
- `YkJpeg::PutBit` calls nothing directly
- `YkJpeg::PutBits` calls `YkJpeg::PutBit`
- `YkJpeg::PutBytes` calls nothing directly
- `YkJpeg::FlushBits` calls nothing directly
- `YkJpeg::CaptureAndEncode` calls `Allocator_Generic`, `YkCommon_BeginCapture`, `YkJpeg::EncodeChecked`, `operator_delete`
